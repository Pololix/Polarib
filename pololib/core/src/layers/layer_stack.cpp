#include "core/layers/layer_stack.h"

#include <algorithm>
#include "core/events/events.h"
#include "dbg/assert.h"
#include "dbg/logs.h"

namespace plb
{
	LayerID LayerStack::attachLayer(std::unique_ptr<Layer> layer, bool overlay)
	{
		layer->m_ID = m_FreeID++;

		if (overlay)
		{
			m_LayerBuffer.push_back(std::move(layer));
			m_LayerBuffer.end()->get()->onAttach();
		}
		else
		{
			m_LayerBuffer.insert(m_LayerBuffer.begin() + m_OverlayIndex, std::move(layer));
			m_LayerBuffer.at(m_OverlyIndex)->onAttach();
			m_OverlayIndex++;
		}

		PLB_LOG_INFO("New layer attached");
		return m_FreeID;
	}

	void LayerStack::detachLayer(LayerID ID)
	{
		size_t pos = getPos(ID);
		if (pos == 0) return; //PLB_TODO: log error

		m_LayerBuffer.at(pos)->onDetach();
		m_LayerBuffer.erase(m_LayerBuffer.begin() + pos);
		if (!overlay) m_OverlayIndex--;
	}

	void LayerStack::suspendLayer(LayerID ID)
	{
		//PLB_TODO: check it wasnt previously suspended
		size_t pos = getPos(ID);
		if (pos == 0) return;

		m_LayerBuffer.at(pos).get()->m_Suspended = true;
		m_LayerBuffer.at(pos).get()->onSuspend();
	}

	void LayerStack::includeLayer(LayerID ID)
	{
		//PLB_TODO: check it wasnt previously included
		size_t pos = getPos(ID);
		if (pos == 0) return;

		m_LayerBuffer.at(pos).get()->m_Suspended = false;
		m_LayerBuffer.at(pos).get()->onInclude();
	}

	void LayerStack::propagateEvent(Event& e) const
	{
		for (auto layer = m_LayerBuffer.rbegin(); layer != m_LayerBuffer.rend();layer++)
		{
			(*layer)->onEvent(e);
			if (e.m_Handled) break;
		}
	}

	void LayerStack::update(float deltaTime) const
	{
		for (auto layer = m_LayerBuffer.rbegin(); layer != m_LayerBuffer.rend(); layer++)
		{
			(*layer)->onUpdate(deltaTime);
		}
	}

	void LayerStack::render() const
	{
		for (auto& layer : m_LayerBuffer)
		{
			layer->onRender();
		}
	}

	unsigned int LayerStack::getPos(LayerID ID) const
	{
		auto target = std::find_if(m_LayerBuffer.begin(), m_LayerBuffer.end(), [ID](const std::unique_ptr<Layer>& layer)
		{
			return layer->m_ID == ID;
		});

		return (target == m_LayerBuffer.end()) ? 0 : static_cast<int>(std::distance(m_LayerBuffer.begin(), target));
	}
}
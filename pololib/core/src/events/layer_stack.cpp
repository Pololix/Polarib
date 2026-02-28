#include "core/events/layer_stack.h"

#include <algorithm>
#include "core/events/events.h"
#include "dbg/assert.h"

namespace plb
{
	LayerID LayerStack::attachOverlay(std::unique_ptr<Layer> layer)
	{
		m_LayerBuffer.emplace_back(std::move(layer), m_FreeID++);
		return m_FreeID;
	}

	LayerID LayerStack::attachUnderlay(std::unique_ptr<Layer> layer)
	{
		m_LayerBuffer.emplace(m_LayerBuffer.begin() + m_OverlayIndex, std::move(layer), m_FreeID++);
		m_OverlayIndex++;
		return m_FreeID;
	}

	void LayerStack::detachOverlay(LayerID ID)
	{
		int pos = getPos(ID);
		if (pos < 0) return;

		m_LayerBuffer.erase(m_LayerBuffer.begin() + pos);
	}

	void LayerStack::detachUnderlay(LayerID ID)
	{
		int pos = getPos(ID);
		if (pos < 0) return;

		m_LayerBuffer.erase(m_LayerBuffer.begin() + pos);
		m_OverlayIndex--;
	}

	void LayerStack::suspendLayer(LayerID ID)
	{
		int pos = getPos(ID);
		if (pos < 0) return;

		Layer* layer = m_LayerBuffer.at(pos).get();
		layer->m_Suspended = true;
		layer->onSuspend();
	}

	void LayerStack::includeLayer(LayerID ID)
	{
		int pos = getPos(ID);
		if (pos < 0) return;

		Layer* layer = m_LayerBuffer.at(pos).get();
		layer->m_Suspended = false;
		layer->onInclude();
	}

	void LayerStack::propagateEvent(Event& e) const
	{
		for (auto layer = m_LayerBuffer.rbegin(); layer != m_LayerBuffer.rend();layer++)
		{
			(*layer).get()->onEvent(e);
			if (e.m_Handled) break;
		}
	}

	void LayerStack::propagateUpdate(float deltaTime) const
	{
		for (auto layer = m_LayerBuffer.rbegin(); layer != m_LayerBuffer.rend(); layer++)
		{
			(*layer).get()->onUpdate(deltaTime);
		}
	}

	int LayerStack::getPos(LayerID ID) const
	{
		auto target = std::find_if(m_LayerBuffer.begin(), m_LayerBuffer.end(), [ID](const Layer& layer) 
		{ 
			return layer.m_ID == ID;
		});

		return (target == m_LayerBuffer.end()) ? -1 : static_cast<int>(std::distance(m_LayerBuffer.begin(), target));
	}
}
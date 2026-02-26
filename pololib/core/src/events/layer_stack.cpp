#include "core/events/layer_stack.h"

#include <algorithm>
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

		Layer* layer = m_LayerBuffer.at(pos).layer.get();
		layer->m_Suspended = true;
		layer->onSuspend();
	}

	void LayerStack::includeLayer(LayerID ID)
	{
		int pos = getPos(ID);
		if (pos < 0) return;

		Layer* layer = m_LayerBuffer.at(pos).layer.get();
		layer->m_Suspended = false;
		layer->onInclude();
	}

	void LayerStack::propagateEvent(Event& e)
	{
		for (auto wrapper = m_LayerBuffer.rbegin(); wrapper != m_LayerBuffer.rend(); wrapper++)
		{
			(*wrapper).layer.get()->onEvent(e));
			if (e.m_Handled) break;
		}
	}

	void LayerStack::propagateUpdate(float deltaTime) const
	{
		for (auto wrapper = m_LayerBuffer.rbegin(); wrapper != m_LayerBuffer.rend(); wrapper++)
		{
			(*wrapper).layer.get()->onUpdate(deltaTime);
		}
	}

	void LayerStack::propagateRender() const
	{
		for (auto wrapper = m_LayerBuffer.begin(); wrapper != m_LayerBuffer.end(); wrapper++)
		{
			(*wrapper).layer.get()->onRender();
		}
	}

	int LayerStack::getPos(LayerID ID) const
	{
		auto target = std::find_if(m_LayerBuffer.begin(), m_LayerBuffer.end(), [ID](LayerWrapper& wrapper) 
		{ 
			return wrapper.ID == ID;
		});

		return (target == m_LayerBuffer.end()) ? -1 : std::distance(m_LayerBuffer.begin(), target);
	}
}
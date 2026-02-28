#pragma once

#include <vector>
#include <memory>
#include "core/layers/layer.h"

namespace plb
{
	class LayerStack
	{
	public:
		LayerID attachOverlay(std::unique_ptr<Layer> layer);
		LayerID attachUnderlay(std::unique_ptr<Layer> layer);

		void detachOverlay(LayerID ID);
		void detachUnderlay(LayerID ID);

		void suspendLayer(LayerID ID);
		void includeLayer(LayerID ID);

		void propagateEvent(Event& e) const;
		void propagateUpdate(float deltaTime) const;
	private:
		std::vector<std::unique_ptr<Layer>> m_LayerBuffer;
		unsigned int m_OverlayIndex = 0;
		LayerID m_FreeID = 0;

		unsigned int getPos(LayerID ID) const;
	};
}
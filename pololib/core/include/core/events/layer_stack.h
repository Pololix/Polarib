#pragma once

#include <vector>
#include <memory>
#include "core/events/layer.h"

namespace plb
{
	using LayerID = unsigned int;

	struct LayerWrapper
	{
		std::unique_ptr<Layer> layer;
		LayerID ID = -1;

		LayerWrapper(std::unique_ptr<Layer> layer, LayerID ID)
			: layer(std::move(layer)), ID(ID) {}
	};

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
		void propagateRender() const;
	private:
		std::vector<LayerWrapper> m_LayerBuffer;
		unsigned int m_OverlayIndex = 0;
		LayerID m_FreeID = 0;

		int getPos(LayerID ID);
	};
}
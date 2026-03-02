#pragma once

#include <vector>
#include <memory>
#include "core/layers/base_layer.h"

namespace plb
{
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack() = default;

		LayerID attachLayer(std::unique_ptr<Layer> layer, bool overlay);
		void detachLayer(LayerID ID);

		void suspendLayer(LayerID ID);
		void includeLayer(LayerID ID);

		void propagateEvent(Event& e) const;
		void update(float deltaTime) const;
		void render() const;
	private:
		std::vector<std::unique_ptr<Layer>> m_LayerBuffer;
		unsigned int m_OverlayIndex = 0;
		LayerID m_FreeID = 0;

		unsigned int getPos(LayerID ID) const;
	};
}
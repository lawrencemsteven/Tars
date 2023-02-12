#include <TarsPCH.h>
#include <Tars/Layers/Layer.h>

namespace Tars {

	Layer::Layer(const std::string& debugName)
		: m_debugName(debugName) {}

	Layer::~Layer() {}

}
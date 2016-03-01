#include "Config.h"

namespace ofx {
namespace DOM {

Config::Config()
{
	name.set("name", "noname");
	alignment.set("alignment",Alignment::Horizontal);
	//shape.setup("shape", );
}

} } // namespace ofx::DOM

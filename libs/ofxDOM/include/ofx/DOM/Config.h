#pragma once

#include "ofMain.h"
#include "ofx/DOM/Types.h"
#include "ofx/DOM/ConfigAttribute.h"

namespace ofx {
namespace DOM {

class Config
{
	public:

		Config();
		ConfigAttribute<std::string> name;
		ConfigAttribute<Alignment> alignment;
		ConfigAttribute<Shape> shape;

};

}} // namespace ofx::DOM

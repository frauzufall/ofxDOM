#pragma once

#include "ofMain.h"
#include "ofx/DOM/Types.h"

namespace ofx {
namespace DOM {

enum Alignment{
	Horizontal,
	Vertical
};
enum TextAlignment{
	Left,
	Right,
	Centered
};

template <typename T>
class ConfigAttribute<T> : ofParameter<T> {
	public:

		ConfigAttribute<T>() : ofParameter<T>(){}

		void setParseFunction(auto parseFunction)
		{
			if(parseFunction){
				this->parse = parseFunction;
			}
		}

		template <typename Output = T, typename Input = std::string>
		virtual std::function<void (Input value)> parse = [](Input s_value){
			this->value = Output(s_value);
		};

		template <typename Output = ofColor>
		virtual std::function<void (std::string value)> parse = [](std::string s_value){
			vector<string> vals = ofSplitString(ofSplitString(ofSplitString(s_value, "rgba(")[0],")"),",");
			ofColor res(ofToFloat(vals[0]), ofToFloat(vals[1]), ofToFloat(vals[2]), ofToFloat(vals[3]));
			return res;
		};

		template <typename Output = ofRectangle>
		virtual std::function<void (ofJson value)> parse = [](ofJson s_value){
			if(s_value["left"]){
				this->value.x = s_value["left"];
			}
			if(s_value["top"]){
				this->value.y = s_value["top"];
			}
			if(s_value["width"]){
				this->value.y = s_value["width"];
			}
			if(s_value["height"]){
				this->value.y = s_value["height"];
			}
		};

};

}} // namespace ofx::DOM

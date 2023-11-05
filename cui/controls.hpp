
#pragma once

#include "include.hpp"

namespace Controls {
	class basic_controls {
		public:
			std::string Name;
			virtual bool Join(); //加入渲染列表
			virtual void Stop(); //移出渲染列表
			virtual void Print() = 0; //渲染（接口）
			virtual void Event(INPUT_RECORD) = 0; //输入（接口）
			bool operator()(const basic_controls* b) const {
				return this->Name < b->Name;
			}
	};
	std::map<std::string, basic_controls*> controls;
	bool basic_controls::Join() {
		if (controls[this->Name] == NULL) {
			controls[this->Name] = this;
			return true;
		} else {
			return false;
		}
	}
	void basic_controls::Stop() {
		controls.erase(controls.find(this->Name));
	}
}

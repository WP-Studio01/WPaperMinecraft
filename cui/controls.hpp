
#pragma once

#include "include.hpp"

namespace Controls {
	class basic_controls {
		public:
			std::string Name;
			virtual bool Join(); //������Ⱦ�б�
			virtual void Stop(); //�Ƴ���Ⱦ�б�
			virtual void Print() = 0; //��Ⱦ���ӿڣ�
			virtual void Event(INPUT_RECORD) = 0; //���루�ӿڣ�
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

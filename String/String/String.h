#pragma once
#ifndef STRING_H
#define STRING_H
#include<assert.h>

class String {
private:
	char* string = nullptr;
	unsigned int allocated_memory = 0u;
	

public:
	String() {}
	~String() {
		if (string != nullptr){
			delete[] string;
			string = nullptr;
			allocated_memory = 0;
		}
	}
	String(const char* string){
		assert(string != nullptr);
		if (string != nullptr) {
			allocated_memory = strlen(string) + 1;
			this->string = new char[allocated_memory];
			strcpy_s(this->string,allocated_memory,string);
		}
	}
	String(const String& chain) {
		this->allocated_memory = chain.allocated_memory;
		this->string = chain.string;
		allocated_memory = strlen(string) + 1;
		this->string = new char[allocated_memory];
		strcpy_s(this->string, allocated_memory, string);
	}
	String operator=(const char* chain) {
		if (strlen(chain) +1 <= this->allocated_memory) {

			allocated_memory = strlen(chain) + 1;
			strcpy_s(this->string, allocated_memory, chain);
		}
	}
	String operator=(String &chain) {
		return String(chain.string);
	}
	void MakeString(unsigned int size, char* ch) {
		for (int i = 0; i < size; i++) {
			string[i] = ch[i];
		}
	}
};
#endif // !STRING_H


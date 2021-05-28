#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class File {
private:
	std::string fileName;
protected:
	std::fstream file_stream;
	std::ifstream file_i;
	std::ofstream file_o;
public:
	File(std::string nmFl = "") { this->fileName = nmFl; }
	~File() { }
	std::string getFileName() { return this->fileName; };
};



template <class T>
class FileTXT : public File {
public:
	FileTXT() {}
	FileTXT(std::string path) :File(path) { }
	void readTxt(T& obj) { this->file_i >> obj; }
	void writeTxt(T& obj) { this->file_o << obj; }

	bool FileTxTeofIn() { return  this->file_i.eof(); }
	bool FileTxTeofOut() { return  this->file_o.eof(); }

	void fileTxTOpenIn();
	void fileTxTOpenOut();


	void fileTxTCloseOut() { this->file_o.close(); }
	void fileTxTCloseIn() { this->file_i.close(); }
	~FileTXT() {}
};


template <class T>
class FileBin : public File {
public:
	FileBin() {	}
	FileBin(std::string path) :File(path) {
		this->file_stream.open(this->getFileName(), std::ios::in | std::ios::out | std::ios::binary);
		if (!this->file_stream.is_open()) {
			std::cout << " File is not opne \n ";
			exit(1);
		}
	}

	~FileBin() { this->file_stream.close(); }

	void ReadBin(T& obj) { this->file_stream >> obj; }
	void WriteBin(T& obj) { this->file_stream << obj; }

	bool EndOfFile() { return this->file_stream.eof(); }
};

// File work with .TXT

template<class T>
inline void FileTXT<T>::fileTxTOpenIn() {
	this->file_i.open(getFileName(), std::ios::in);
	if (!file_i.is_open()) {
		std::cout << " error open the fileTXT for write  \n" << getFileName() << std::endl;
		return;
	}
}

template<class T>
inline void FileTXT<T>::fileTxTOpenOut() {
	this->file_o.open(getFileName(), std::ios::out);
	if (!file_o.is_open()) {
		std::cout << " error open the fileTXT \n" << getFileName() << std::endl;
		return;
	}
}
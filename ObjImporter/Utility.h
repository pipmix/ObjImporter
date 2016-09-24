#pragma once
#include "Headers.h"

extern vector<wstring> names;
extern vector<wstring> folders;
extern vector<wstring> goodNames;

void PrintVector(vector<wstring> vecToPrint) {

	for (auto s : vecToPrint)wcout << s << endl;

}


wstring GetProgramFolder() {

	WCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	wstring::size_type pos = wstring(buffer).find_last_of(L"\\/");
	wstring direct = wstring(buffer).substr(0, pos);
	direct += L"\\";
	return direct;

}

void GetFileNamesFromAFolder(wstring folder) {

	wchar_t sp[128];
	wsprintf(sp, L"%s/*.*", folder.c_str());
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(sp, &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) names.push_back(fd.cFileName); // is a file
			else folders.push_back(fd.cFileName); // is a folder

		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}


void GetFileNamesOfType(wstring type) {
	// Sorts through "names" and puts the good ones in "good names"
	for (int i = 0; i < names.size(); i++) {
		wstring fn = names[i];
		if (fn.substr(fn.find_last_of(L".") + 1) == type) {

			size_t lastindex = fn.find_last_of(L".");
			wstring rawname = fn.substr(0, lastindex);

			goodNames.push_back(rawname);
		}
	}
}

void GetFileNamesOfTypeWithExt(wstring type) {
	// Sorts through "names" and puts the good ones in "good names"
	for (int i = 0; i < names.size(); i++) {
		wstring fn = names[i];
		if (fn.substr(fn.find_last_of(L".") + 1) == type) {

			
			wstring rawname = fn;

			goodNames.push_back(rawname);
		}
	}
}


wstring StripExtension(wstring toStrip) {

	size_t lastindex = toStrip.find_last_of(L".");
	return toStrip.substr(0, lastindex);

}
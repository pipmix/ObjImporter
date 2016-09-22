/*
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <d3d11_1.h>
#pragma comment (lib, "d3d11.lib")
#include <DirectXMath.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>         
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <codecvt>
#include <cstdint>
using namespace std;
using namespace DirectX;



bool slim = true;
vector<wstring> names;
vector<wstring> folders;
vector<wstring> goodNames;


void get_all_files_names_within_folder(wstring folder){



	wchar_t sp[128];
	wsprintf(sp, L"%s/*.*", folder.c_str());
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(sp, &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
			else //Put folders into vector
			{
				folders.push_back(fd.cFileName);
			}

		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	if (!slim) {

		for (int i = 0; i < names.size(); i++) {
			wcout << names[i] << endl;

		}
		for (int i = 0; i < folders.size(); i++) {
			//wcout << folders[i] << endl;

		}


	}

	
}






struct COMB {

	COMB(string st, int ind) : tupleName(st), indexNum(ind) {};
	string tupleName;
	int indexNum;
};



struct VERTEX {
	XMFLOAT3 pos;
	XMFLOAT3 normal;
	XMFLOAT2 uv;
	VERTEX(XMFLOAT3 p, XMFLOAT3 n, XMFLOAT2 u) {
		pos = p;
		normal = n;
		uv = u;
	}
	VERTEX() {

	}
};




void main() {



	// OPEN FILE

	wstring importFileName = L"wallTopFloor";
	wstring fileDirectory = L"c:/files/Meshes/";
	wstring wFileDirectory = L"c:/files/Meshes/";
	wstring importfileType = L".obj";
	wstring exportFileType = L".mesh";
	wstring fullImportName = fileDirectory + importFileName + importfileType;
	wstring fullExportFileName = fileDirectory + importFileName + exportFileType;


	// GET FILE NAMES IN DIR
	get_all_files_names_within_folder(wFileDirectory);
	for (int i = 0; i < names.size(); i++) {
		wstring fn = names[i];
		if (fn.substr(fn.find_last_of(L".") + 1) == L"obj") {

			size_t lastindex = fn.find_last_of(L".");
			wstring rawname = fn.substr(0, lastindex);

			goodNames.push_back(rawname);

		}
	}


	for (int i = 0; i < goodNames.size(); i++) {
		wcout << goodNames[i] << endl;

	}


	for (int i = 0; i < goodNames.size(); i++) {


		vector<string> wholeList;
		vector<string> tuples;
		vector<VERTEX> faces;
		vector<int> indices;
		VERTEX * ar = nullptr;
		vector<COMB> combList;

		string materialName;
		string textureName;

		int numberOfVerts = 0;

		wchar_t curChar0;

		
		importFileName = goodNames[i];
		fullImportName = fileDirectory + importFileName + importfileType;
		fullExportFileName = fileDirectory + importFileName + exportFileType;





		ifstream file(fullImportName);
		vector<int> indexLoc;
		int indexLocCount = 0;
		vector<XMFLOAT3> pos;
		vector<XMFLOAT3> normal;
		vector<XMFLOAT2> uv;
		vector<string> listOfVerts;
		wchar_t curChar;
		float x, y, z;
		string f1, f2, f3;

		// GO THROUGH FILE
		if (file) {
			while (file) {
				curChar = file.get();
				switch (curChar) {
				case 'm':
					curChar = file.get();
					if (curChar == 't')curChar = file.get();
					if (curChar == 'l')curChar = file.get();
					if (curChar == 'l')curChar = file.get();
					if (curChar == 'i')curChar = file.get();
					if (curChar == 'b')curChar = file.get();
					if (curChar == ' ')file >> textureName;
					break;
				case 'u':
					curChar = file.get();
					if (curChar == 's')curChar = file.get();
					if (curChar == 'e')curChar = file.get();
					if (curChar == 'm')curChar = file.get();
					if (curChar == 't')curChar = file.get();
					if (curChar == 'l')curChar = file.get();
					if (curChar == ' ')file >> materialName;
					break;
				case'#':

					while (file.get() != '\n') {

					}


					break;

				case 'v':
					curChar = file.get();
					if (curChar == ' ') {
						file >> x >> y >> z;
						pos.push_back(XMFLOAT3(x, y, z));
					}
					else if (curChar == 't') {
						curChar = file.get();
						file >> x >> y;
						uv.push_back(XMFLOAT2(x, y));
					}
					else if (curChar == 'n') {
						curChar = file.get();
						file >> x >> y >> z;
						normal.push_back(XMFLOAT3(x, y, z));
					}
					break;
				case 'f':
					curChar = file.get();
					file >> f1 >> f2 >> f3;

					wholeList.push_back(f1);
					wholeList.push_back(f2);
					wholeList.push_back(f3);

					// ADD THE UNIQUE TUPLES STRINGS TO VERTEX LIST
					if (std::find(listOfVerts.begin(), listOfVerts.end(), f1) == listOfVerts.end()) {
						combList.push_back(COMB(f1, indexLocCount));
						listOfVerts.push_back(f1);
						//indexLoc.push_back(indexLocCount);
						indexLocCount++;

					}
					if (std::find(listOfVerts.begin(), listOfVerts.end(), f2) == listOfVerts.end()) {
						combList.push_back(COMB(f2, indexLocCount));
						listOfVerts.push_back(f2);
						//indexLoc.push_back(indexLocCount);
						indexLocCount++;

					}
					if (std::find(listOfVerts.begin(), listOfVerts.end(), f3) == listOfVerts.end()) {
						combList.push_back(COMB(f3, indexLocCount));
						listOfVerts.push_back(f3);
						//indexLoc.push_back(indexLocCount);
						indexLocCount++;

					}


					break;
				default:
					break;
				}
			}



			//USE THE STRINGS TO MAKE THE VERTEXS
			int a, b, c;
			char c1, c2;
			numberOfVerts = listOfVerts.size();

			//VERTEX * ar = new VERTEX[numberOfVerts];
			ar = new VERTEX[numberOfVerts];
			for (int i = 0; i < listOfVerts.size();i++) {
				istringstream buf(listOfVerts[i]);
				if (buf >> a >> c1 >> b >> c2 >> c && c1 == '/' && c2 == '/') {
					faces.push_back(VERTEX(pos[a - 1], normal[c - 1], uv[b - 1]));
					indices.push_back(a);
					indices.push_back(b);
					indices.push_back(c);
				}
			}
			for (int i = 0; i < faces.size(); i++)ar[i] = faces[i];

			file.close();
		}


		vector<int> indicesFinal;
		ofstream outputFile(fullExportFileName);

		int quickCount = 0;

		if (!slim)std::cout << endl << textureName << endl << materialName << "\n" << wholeList.size() << "\n" << faces.size() << endl;
		else outputFile << textureName << " " << materialName << " " << wholeList.size() << " " << faces.size() << " \n";

		

		for (int i = 0; i < wholeList.size(); i++) {

			for (int j = 0; j < combList.size(); j++) {
				if (wholeList[i].compare(combList[j].tupleName) == 0) {




					if (!slim) std::cout << combList[j].indexNum;
					else {
						//outputFile << combList[j].indexNum;
						indicesFinal.push_back(combList[j].indexNum);
					}



					if (!slim) std::cout << ", ";
					else {
						;
						//outputFile << " ";
					}
					quickCount++;
					if (quickCount == 3) {
						if (!slim) std::cout << endl;
						quickCount = 0;
					}

				}
			}

			
		}

		if (slim) {
			for (int i = 0; i < indicesFinal.size(); i++) {

				if ((i % 3) == 0) {
					outputFile << indicesFinal[i + 2] << " " << indicesFinal[i + 1] << " " << indicesFinal[i] << " ";
				}

				

			}


		}


		if (!slim) {

			for (int i = 0; i < faces.size(); i++) {

				std::cout << "{   XMFLOAT3( ";

				if (faces[i].pos.x == (int)faces[i].pos.x) std::cout << faces[i].pos.x << ".0";
				else std::cout << faces[i].pos.x;

				std::cout << "f, ";

				if (faces[i].pos.y == (int)faces[i].pos.y) std::cout << faces[i].pos.y << ".0";
				else std::cout << faces[i].pos.y;

				std::cout << "f, ";

				if (faces[i].pos.z == (int)faces[i].pos.z) std::cout << faces[i].pos.z << ".0";
				else std::cout << faces[i].pos.z;

				std::cout << "f ";

				std::cout << "), ";

				std::cout << "XMFLOAT3( ";

				if (faces[i].normal.x == (int)faces[i].normal.x) std::cout << faces[i].normal.x << ".0";
				else std::cout << faces[i].normal.x;

				std::cout << "f, ";

				if (faces[i].normal.y == (int)faces[i].normal.y) std::cout << faces[i].normal.y << ".0";
				else std::cout << faces[i].normal.y;

				std::cout << "f, ";

				if (faces[i].normal.z == (int)faces[i].normal.z) std::cout << faces[i].normal.z << ".0";
				else std::cout << faces[i].normal.z;

				std::cout << "f ";

				std::cout << "), ";

				std::cout << "XMFLOAT2( ";

				if (faces[i].uv.x == (int)faces[i].uv.x) std::cout << faces[i].uv.x << ".0";
				else std::cout << faces[i].uv.x;

				std::cout << "f, ";

				if (faces[i].uv.y == (int)faces[i].uv.y) std::cout << faces[i].uv.y << ".0";
				else std::cout << faces[i].uv.y;

				std::cout << "f ";
				std::cout << ") }," << endl;

				//cout  << "{ XMFLOAT3( " << faces[i].pos.x << ", " << faces[i].pos.y << ", " << faces[i].pos.z << "), " <<
				//	"XMFLOAT3( " << faces[i].normal.x << ", " << faces[i].normal.y << ", " << faces[i].normal.z << "), " <<
				//	"XMFLOAT2( " << faces[i].uv.x << ", " << faces[i].uv.y << ") }," << endl;

			}

		}
		else

			for (int i = 0; i < faces.size(); i++) {

				outputFile << faces[i].pos.x << " " << faces[i].pos.y << " " << (faces[i].pos.z * -1.0f) << " ";
				outputFile << faces[i].normal.x << " " << faces[i].normal.y << " " << (faces[i].normal.z * -1.0f) << " ";
				outputFile << faces[i].uv.x << " " << (1.0f - faces[i].uv.y) << " ";

			}
		outputFile.close();









	}

	wstring gPath = L"check/to";
	wstring gMeshPath = L"see";
	wstring fileName = L"dfifsomething";



	wstring completePathAndName = gPath+ gMeshPath + fileName + L".mesh";

	
	string s(completePathAndName.begin(), completePathAndName.end());





	std::cout << s << endl;


}


*/
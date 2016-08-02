/*
#include <iostream>
#include <d3d11_1.h>
#pragma comment (lib, "d3d11.lib")
#include <DirectXMath.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
using namespace DirectX;

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

	vector<VERTEX> faces;
	vector<int> indices;
	VERTEX * ar = nullptr;

	int numberOfVerts = 0;

	wchar_t curChar0;
	ifstream file0("mesh.txt");

	if (file0) {
		while (file0) {
			curChar0 = file0.get();

		}
	}




	file0.close();



	ifstream file("mesh3.txt");





	vector<XMFLOAT3> pos;
	vector<XMFLOAT3> normal;
	vector<XMFLOAT2> uv;
	vector<string> listOfVerts;
	wchar_t curChar;
	float x, y, z;
	string f1, f2, f3;

	if (file) {
		while (file) {
			curChar = file.get();
			switch (curChar) {
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
				listOfVerts.push_back(f1);
				listOfVerts.push_back(f2);
				listOfVerts.push_back(f3);
				break;
			default:
				break;
			}
		}

		std::sort(listOfVerts.begin(), listOfVerts.end());
		listOfVerts.erase(std::unique(listOfVerts.begin(), listOfVerts.end()), listOfVerts.end());



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
	}



	int counn = 1;

	for (int i = 0; i < numberOfVerts; i++) {

		//cout << faces[i].pos.x << " " << faces[i].pos.y << " " << faces[i].pos.z << " | " <<
		//	faces[i].normal.x << " " << faces[i].normal.y << " " << faces[i].normal.z << " | " <<
		//	faces[i].uv.x << " " << faces[i].uv.y << endl;

		cout << "{ XMFLOAT3(" << faces[i].pos.x << "f, " << faces[i].pos.y << "f, " << faces[i].pos.z << "f)," <<
			"XMFLOAT3( " << faces[i].normal.x << ", " << faces[i].normal.y << ", " << faces[i].normal.z << "), " <<
			"XMFLOAT2( " << faces[i].uv.x << ", " << faces[i].uv.y << ")}, " << endl;

		counn++;
	}



	//std::copy(v.begin(), v.end(), arr);



	/*

	std::sort(listOfVerts.begin(), listOfVerts.end());
	listOfVerts.erase(std::unique(listOfVerts.begin(), listOfVerts.end()), listOfVerts.end());

	int countt = 1;
	for (auto i = listOfVerts.begin(); i != listOfVerts.end(); ++i) {
	std::cout << countt << ":  " << *i << ' ' << endl;
	countt++;
	}
	*/
/*
	int countt = 1;
	int rowCount = 0;
	for (auto i = indices.begin(); i != indices.end(); i) {

		if (rowCount == 0) {
			//cout << countt << ": ";

		}


		cout << *i + 2 << ", " << *i + 1 << ", " << *i << ", " << endl;
		i = i + 3;

		rowCount++;


		if (rowCount == 3) {
			rowCount = 0;
			countt++;
		}
		else {

		}

	}




}


*/
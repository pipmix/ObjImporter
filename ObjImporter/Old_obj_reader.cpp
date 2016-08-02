/*

#include <iostream>
#include <d3d11_1.h>
#pragma comment (lib, "d3d11.lib")
#include <DirectXMath.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
	VERTEX * ar = nullptr;

	int numberOfVerts = 0;


	ifstream file("mesh.txt");

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
		//USE THE STRINGS TO MAKE THE VERTEXS
		int a, b, c;
		char c1, c2;
		numberOfVerts = listOfVerts.size();

		//VERTEX * ar = new VERTEX[numberOfVerts];
		ar = new VERTEX[numberOfVerts];
		for (int i = 0; i < listOfVerts.size();i++) {
			istringstream buf(listOfVerts[i]);
			if (buf >> a >> c1 >> b >> c2 >> c && c1 == '/' && c2 == '/')faces.push_back(VERTEX(pos[a - 1], normal[c - 1], uv[b - 1]));
		}
		for (int i = 0; i < faces.size(); i++)ar[i] = faces[i];
	}




	for (int i = 0; i < numberOfVerts; i++) {

		//cout << faces[i].pos.x << " " << faces[i].pos.y << " " << faces[i].pos.z << " | " <<
		//	faces[i].normal.x << " " << faces[i].normal.y << " " << faces[i].normal.z << " | " <<
		//	faces[i].uv.x << " " << faces[i].uv.y << endl;

		cout << "VertexP(" << faces[i].pos.x << "f, " << faces[i].pos.y << "f, " << faces[i].pos.z << "f)," << endl;




	}

	//std::copy(v.begin(), v.end(), arr);




}


*/
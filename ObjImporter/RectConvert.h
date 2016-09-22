#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <DirectXMath.h>
using namespace std;
using namespace DirectX;

extern wstring gCurImportDirectory;
extern wstring gCurImportFileName;
extern wstring gCurImportFileExt;

extern wstring gCurExportDirectory;
extern wstring gCurExportFileName;
extern wstring gCurExportFileExt;


void RectConvert() {

	wchar_t curChar;

	string mapName;
	int numOfRects;
	float maxLeft, maxTop, maxRight, maxBottom;

	float x, y, z;
	vector<XMFLOAT3> pos;
	vector<XMFLOAT2> uv;
	vector<XMFLOAT3> normal;

	wstring importCompletePathAndName = gCurImportDirectory + gCurImportFileName + L"." + gCurImportFileExt;
	wstring exportCompletePathAndName = gCurExportDirectory + gCurExportFileName + L"." + gCurExportFileExt;

	ifstream file(importCompletePathAndName);
	// Read in obj file
	if (file) {
		while (file) {
			curChar = file.get();
			switch (curChar) {
				case'#':
					while (file.get() != '\n') { ; }
					break;
				case 'v': 
					curChar = file.get();
					if (curChar == ' ') {
						file >> x >> y >> z;
						pos.push_back(XMFLOAT3(x, y, z));
					}
					else if (curChar == 't') {
						while (file.get() != '\n') { ; }
						break;
					}
					else if (curChar == 'n') {
						while (file.get() != '\n') { ; }
						break;
					}
					break;

				case 'g': 
					while (file.get() != '\n') { ; }
					break;
				case 'f':
					while (file.get() != '\n') { ; }
					break;

				default:
					break;

			} //switch(curChar)
		} // while(file)
		file.close();
	} // if(file)

	// Export collision
	ofstream outputFile(exportCompletePathAndName);
	mapName = "tempMap";
	numOfRects = pos.size() / 4;
	bool printWH = true;
	bool printRB = false;

	outputFile << mapName << " " << numOfRects << endl;
	float left, top, right, bottom, width, height;

	for (int i = 0; i < pos.size(); i += 4) {
		bottom	=	pos[i + 0].y;
		left	=	pos[i + 0].x;
		top		=	pos[i + 3].y;
		right	=	pos[i + 3].x;
		width	=	abs(right - left);
		height	=	abs(bottom - top);

		outputFile << left << " " << top;
		if (printRB)outputFile << " " << right << " " << bottom;
		if (printWH)outputFile << " " << width << " " << height;
		outputFile << endl;

	}


	outputFile.close();



}

void RectLoad() {


	wstring completePathAndName = gCurImportDirectory + gCurImportFileName + L"." + gCurImportFileExt;
	string completeName(completePathAndName.begin(), completePathAndName.end());
	wchar_t curChar;
	int numOfRects;
	string fileName;
	XMFLOAT4* rects;

	ifstream file(completePathAndName);

	if (file) {

		file >> fileName >> numOfRects;
		rects = new XMFLOAT4[numOfRects];

		for (int i = 0; i < numOfRects; i++) {
			file >> rects[i].x >> rects[i].y >> rects[i].z >> rects[i].w;
		}
		file.close();

	}


	// Verification
	for (int i = 0; i < numOfRects; i++) {

		cout << i << "\t" << rects[i].x << "\t" << rects[i].y << "\t" << rects[i].z << "\t" << rects[i].w << endl;
	}



}
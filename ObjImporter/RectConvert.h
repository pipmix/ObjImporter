#pragma once
#include "Headers.h"

using namespace std;
using namespace DirectX;

extern wstring gCurImportDirectory;
extern wstring gCurImportFileName;
extern wstring gCurImportFileExt;

extern wstring gCurExportDirectory;
extern wstring gCurExportFileName;
extern wstring gCurExportFileExt;

extern vector<wstring> names;
extern vector<wstring> folders;
extern vector<wstring> goodNames;




void RectConvert(wstring dir) {

	wstring exportExtension = L"rect";

	for (auto s : goodNames){
	
		//	importFileName = goodNames[i];
		wstring fullImportName = dir + s;
		wstring fullExportName = dir + exportExtension;

		wchar_t curChar;

		string mapName;
		int numOfRects;
		float maxLeft, maxTop, maxRight, maxBottom;

		float x, y, z;
		vector<XMFLOAT3> pos;
		vector<XMFLOAT2> uv;
		vector<XMFLOAT3> normal;


		ifstream file(fullImportName);
		wcout << "Opening " << fullImportName << endl;
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
		ofstream outputFile(fullExportName);
		mapName = "tempMap";
		numOfRects = pos.size() / 4;
		bool printWH = false;
		bool printRB = true;

		outputFile << mapName << " " << numOfRects << endl;
		float left, top, right, bottom, width, height;

		for (int i = 0; i < pos.size(); i += 4) {
			//left = [0].x
			//top = [3].y
			//right = [2].x
			//bottom = [0].y
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
	} // auto i goodnames


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
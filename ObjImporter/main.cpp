#include "RectConvert.h"

wstring gCurImportDirectory = L"C:/Box/Box Sync/Data/Exporters/BoxCollision/";
wstring gCurImportFileName = L"onlycollision";
wstring gCurImportFileExt = L"obj";


wstring gCurExportDirectory = L"C:/Box/Box Sync/Data/Exporters/BoxCollision/";
wstring gCurExportFileName = L"ex1";
wstring gCurExportFileExt = L"col";

int main() {

	RectConvert();
	

	gCurImportFileName = L"ex1";
	gCurImportFileExt = L"col";
	RectLoad();

	return 0;
}




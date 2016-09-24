#include "RectConvert.h"
#include "ObjToMesh.h"
wstring gCurImportDirectory = L"C:/Box/Box Sync/Data/Exporters/BoxCollision/";
wstring gCurImportFileName = L"onlycollision";
wstring gCurImportFileExt = L"obj";


wstring gCurExportDirectory = L"C:/Box/Box Sync/Data/Exporters/BoxCollision/";
wstring gCurExportFileName = L"ex1";
wstring gCurExportFileExt = L"col";

extern vector<wstring> names;
extern vector<wstring> folders;
extern vector<wstring> goodNames;

int main() {


	//WCHAR buffer[MAX_PATH];
	//GetModuleFileName(NULL, buffer, MAX_PATH);
	//wstring::size_type pos = wstring(buffer).find_last_of(L"\\/");
	//wstring direct =  wstring(buffer).substr(0, pos);
	//direct += L"\\";

	//wcout << direct << endl << endl;

	/// RECT CONVERT.h /// Converts collision squares
	//RectConvert();
	//gCurImportFileName = L"ex1";
	//gCurImportFileExt = L"col";
	//RectLoad();


	/// ObjToMesh.h  /// convert all .obj to .mesh 
	//ConvertAllObjInDirectory(direct);

	wstring directory;



	return 0;
}



//1. multiply the z  by -1.
//2. reverse the order of the vertices A B C = C B A).


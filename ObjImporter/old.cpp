/*
#include <iostream>
#include <fstream>
#include <string>
#include <d3d11.h>
#include <DirectXMath.h>
#pragma comment(lib,"d3d11.lib")

using namespace std;
using namespace DirectX;

struct VERTEXPNU {
XMFLOAT3 pos;
XMFLOAT3 normal;
XMFLOAT2 uv;
};




int main() {


const wstring gPath = L"C:/Files/";
const wstring gTexturePath = L"Textures/";
const wstring gShaderPath = L"Shaders/";
const wstring gMeshPath = L"Meshes/";
wstring fileName = L"wall01";


wstring completePathAndName = gPath + gMeshPath + fileName + L".mesh";



string completeName(completePathAndName.begin(), completePathAndName.end());



ifstream file(completePathAndName);
wchar_t curChar;

//unsigned short meshIndices[];

string materialName;
string textureName;
int numOfVertices;
int numOfIndices;




if (file) {

file >> materialName >> textureName >> numOfIndices >> numOfVertices;


unsigned short* indices = new unsigned short[numOfIndices];

for (int i = 0; i < numOfIndices; i++) {
file >> indices[i];
}

VERTEXPNU* vertices = new VERTEXPNU[numOfVertices];

for (int i = 0; i < numOfVertices; i++) {

file	>> vertices[i].pos.x
>> vertices[i].pos.y
>> vertices[i].pos.z
>> vertices[i].normal.x
>> vertices[i].normal.y
>> vertices[i].normal.z
>> vertices[i].uv.x
>> vertices[i].uv.y;

}




file.close();

for (int i = 0; i < numOfIndices; i++) {
cout << indices[i] << " " << endl;
}
for (int i = 0; i < numOfVertices; i++) {
cout << vertices[i].pos.x << " " << vertices[i].pos.y << " " << vertices[i].pos.z << " " <<
vertices[i].normal.x << " " << vertices[i].normal.y << " " << vertices[i].normal.z << " " <<
vertices[i].uv.x << " " << vertices[i].uv.y << " " ;






}

delete[] vertices;
delete[] indices;

}


cout << materialName << " " << textureName << " " << numOfVertices << " " << numOfIndices;

}
*/
#include "Graf.h"
#include "edge.h"

void Graf::createVertices(int ile) {
    //vertexList.reserve(ile);
    list.resize(ile);
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    // edge e = edge(i_Vertex_Index_1,i_Vertex_Index_2);
    // vertexList.at(i_Vertex_Index_1).push_back(e);

    list.at(i_Vertex_Index_1).push_back(i_Vertex_Index_2);
}

bool Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    if(checkEdge(i_Vertex_Index_1,i_Vertex_Index_2)) {
        for(int i = 0; i < (int)list.at(i_Vertex_Index_1).size(); i++) {
            if (list.at(i_Vertex_Index_1).at(i) == i_Vertex_Index_2)
                list.at(i_Vertex_Index_1).erase(list.at(i_Vertex_Index_1).begin() + i);
        }
        return true;
    }
    return false;
}
bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    if(std::find(list.at(i_Vertex_Index_1).begin(), list.at(i_Vertex_Index_1).end(), i_Vertex_Index_2) 
        != list.at(i_Vertex_Index_1).end())
        return true;
    return false;
}

int Graf::vertexDegree(int idx) {
    return (int)list.at(idx).size();
}

std::vector<int> Graf::getNeighbourIndices(int idx) {
    return (std::vector<int>)list.at(idx);
}
void Graf::printNeighbourIndices(int idx) {
    std::cout << "Vertex (" << idx << ") neighbours indices: ";
    for( int i = 0; i < (int)list.at(idx).size(); i++ )
        std::cout << list.at(idx).at(i) << " ";
    std::cout << "\n";
}

int Graf::getNumberOfEdges() {
    int suma = 0;
    for(int i = 0; i < (int)list.size(); i ++) 
        suma += list.at(i).size();
    return suma;
}

void Graf::readFromFile(std::string path) {
    std::ifstream in;
    in.open(path);
    if(!in.is_open()) {
        std::cerr << "File opening failure!\n";
        std::abort();
    }
    
    int ile;
    in >> ile;
    this->createVertices(ile);

    int index1,index2;
    while(in >> index1 >> index2)
        this->addEdge(index1, index2);

    in.close();
}
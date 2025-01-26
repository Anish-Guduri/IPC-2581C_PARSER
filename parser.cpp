#include <iostream>
#include <fstream>
#include "tinyxml2.h"
#include "TreeNode.h"
#include "XmlTreeBuilder.h"

using namespace std;
using namespace tinyxml2;

int main() {
    // Load the XML file
    XMLDocument xmlDoc;
    if (xmlDoc.LoadFile("/home/anish/anish/IPC_parser/testcase10-RevC-Assembly.xml") != XML_SUCCESS) {
        cerr << "Error: Unable to load XML file!" << endl;
        return -1;
    }

    // Get the root element
    XMLElement* root = xmlDoc.RootElement();
    if (!root) {
        cerr << "Error: No root element found in the XML file!" << endl;
        return -1;
    }

    // Create the tree builder
    XmlTreeBuilder treeBuilder;

    // Parse the root element into a tree
    TreeNode rootTree = treeBuilder.parseXmlElement(root);

    // Write the tree to a file
    ofstream outFile("tree_output.txt");
    if (!outFile) {
        cerr << "Error: Unable to create output file!" << endl;
        return -1;
    }

    rootTree.writeTreeToFile(outFile);
    outFile.close();

    cout << "Tree structure saved to tree_output.txt" << endl;
    return 0;
}

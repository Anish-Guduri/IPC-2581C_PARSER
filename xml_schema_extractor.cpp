#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

// Class representing a single node in the tree
class TreeNode {
public:
    string name;
    vector<TreeNode> children;

    // Constructor
    TreeNode(const string& nodeName) : name(nodeName) {}

    // Add a child node
    void addChild(const TreeNode& child) {
        children.push_back(child);
    }

    // Write the schema to a file recursively
    void writeSchemaToFile(ofstream& outFile, int depth = 0) const {
        // Indentation for hierarchy
        string indent(depth * 2, ' ');

        // Write the element name
        outFile << indent << name << endl;

        // Recursively write children
        for (const auto& child : children) {
            child.writeSchemaToFile(outFile, depth + 1);
        }
    }
};

// Class responsible for parsing XML and building the tree
class XmlSchemaBuilder {
public:
    // Function to parse an XML element into a TreeNode for schema
    TreeNode parseXmlElementForSchema(XMLElement* element) {
        TreeNode node(element->Name());

        // Add children elements
        XMLElement* child = element->FirstChildElement();
        while (child) {
            node.addChild(parseXmlElementForSchema(child));
            child = child->NextSiblingElement();
        }

        return node;
    }
};

int main() {
    // Load the XML file
    XMLDocument xmlDoc;
    if (xmlDoc.LoadFile("testcase10-RevC-Assembly.xml") != XML_SUCCESS) {
        cerr << "Error: Unable to load XML file!" << endl;
        return -1;
    }

    // Get the root element
    XMLElement* root = xmlDoc.RootElement();
    if (!root) {
        cerr << "Error: No root element found in the XML file!" << endl;
        return -1;
    }

    // Create the schema builder
    XmlSchemaBuilder schemaBuilder;

    // Parse the root element into a schema tree
    TreeNode rootTree = schemaBuilder.parseXmlElementForSchema(root);

    // Write the schema to a file
    ofstream outFile("xml_schema.txt");
    if (!outFile) {
        cerr << "Error: Unable to create output file!" << endl;
        return -1;
    }

    rootTree.writeSchemaToFile(outFile);
    outFile.close();

    cout << "XML schema saved to xml_schema.txt" << endl;
    return 0;
}

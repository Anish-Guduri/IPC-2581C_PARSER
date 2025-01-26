#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Class representing a single node in the tree
class TreeNode {
public:
    string name;
    vector<pair<string, string>> attributes; // Attributes as key-value pairs
    string text;
    vector<TreeNode> children;

    // Constructor
    explicit TreeNode(const string& nodeName);

    // Add an attribute
    void addAttribute(const string& key, const string& value);

    // Add a child node
    void addChild(const TreeNode& child);

    // Set text content
    void setText(const string& content);

    // Write the tree to a file recursively
    void writeTreeToFile(ofstream& outFile, int depth = 0) const;
};

#endif // TREENODE_H

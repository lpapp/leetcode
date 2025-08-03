#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Trie Node which is used internally in FileSystem.
struct TrieNode {
    string name{}; // Name of the file or directory
    bool isFile{false}; // Flag indicating whether it is a file or not
    string content; // Content of the file if it is a file
    unordered_map<string, TrieNode*> children; // Child nodes, representing files and directories

    ~TrieNode() {
        for (auto child : children) delete child.second;
    }

    // Method to insert a node and return the last node in the path. Creates
    // intermediate directories as needed.
    TrieNode* insert(const string& path, bool fileStatus) {
        TrieNode* node = this;
        // Start iterating the path from the character following the initial
        // '/'
        size_t prevPos = 1;
        size_t currentPos = path.find('/', prevPos);

        while (currentPos != string::npos) {
            string part = path.substr(prevPos, currentPos - prevPos);
            // If child does not exist, create it
            if (!node->children.contains(part)) node->children[part] = new TrieNode();

            node = node->children[part];
            prevPos = currentPos + 1;
            currentPos = path.find('/', prevPos);
        }

        // handle the last part of the path
        string part = path.substr(prevPos);
        // If child does not exist, create it
        if (!node->children.contains(part)) node->children[part] = new TrieNode();

        node = node->children[part];
        node->isFile = fileStatus;
        // Set the name of the file
        if (fileStatus) node->name = part;
        return node;
    }


    // Method to search for a node given a path.
    TrieNode* search(const string& path) {
        TrieNode* node = this;
        // Start iterating the path from the character following the initial '/'
        size_t prevPos = 1;
        size_t currentPos = path.find('/', prevPos);
        while (currentPos != string::npos) {
            string part = path.substr(prevPos, currentPos - prevPos);
            // Node not found
            if (!node->children.count(part)) return nullptr;
            node = node->children[part];
            prevPos = currentPos + 1;
            currentPos = path.find('/', prevPos);
        }

        // Handle the last part of the path
        string part = path.substr(prevPos);
        // Node not found
        if (!node->children.count(part)) return nullptr;
        return node->children[part]; // Node found
    }
};

// Definition of a FileSystem that uses a TrieNode structure to manage files
// and directories.
class FileSystem {
    TrieNode* root; // Root directory of the file system
public:
    FileSystem() {
        root = new TrieNode(); // Initialize root
    }

    ~FileSystem() {
        delete root;
    }

    // List the contents in a directory or return the file if it's just a
    // single file.
    vector<string> ls(const string& path) {
        vector<string> result;
        TrieNode* node = root->search(path);
        // Empty vector if path not found
        if (!node) return result;

        // If it's a file, add the file name to the result list
        if (node->isFile) result.push_back(node->name);
        else {
            // If it's a directory, add all the child names to the list
            for (const auto& [name, child]: node->children) result.push_back(name);
        }

        // Sort the list lexicographically
        sort(result.begin(), result.end());
        return result;
    }

    // Make a directory given a path.
    void mkdir(const string& path) {
        root->insert(path, false);
    }

    // Add content to the file, create the file if it does not exist.
    void addContentToFile(const string& filePath, const string& content) {
        TrieNode* node = root->insert(filePath, true);
        node->content += content; // Append the content to the file's content
    }

    // Read content from a file.
    string readContentFromFile(const string& filePath) {
        TrieNode* node = root->search(filePath);
        // Return file content as a String
        if (node && node->isFile) return node->content;

        // Return empty String if file does not exist or if it's a directory
        return {};
    }
};

int main()
{
    return 0;
}

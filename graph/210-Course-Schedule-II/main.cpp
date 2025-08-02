#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Course {
    vector<Course*> children;
    unordered_map<int, Course*> map;
    int courseId;
    int dependencies{0};
public:
    Course(int course): courseId(course) {}
    void addNeighbor(Course* node) {
        const int id = node->getCourseId();
        if (!map.contains(id)) {
            children.push_back(node);
            map[id] = node;
            node->incrementDependencies();
        }
    }

    void incrementDependencies() { ++dependencies; }
    void decrementDependencies() { --dependencies; }

    int getCourseId() { return courseId; }
    vector<Course*> getChildren() { return children; }
    int getNumberOfDependencies() { return dependencies; }
};

class Graph {
    vector<Course*> nodes;
    unordered_map<int, Course*> map;
public:
    Course* getOrCreateNode(int id) {
        if (!map.contains(id)) {
            Course* node = new Course(id);
            nodes.push_back(node);
            map[id] = node;
        }

        return map[id];
    }

    void addEdge(int startId, int endId) {
        Course* startCourse = getOrCreateNode(startId);
        Course* endCourse = getOrCreateNode(endId);
        startCourse->addNeighbor(endCourse);
    }

    vector<Course*> getNodes() { return nodes; }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph = buildGraph(numCourses, prerequisites);
        vector<int> result;
        vector<Course*> nodes = graph.getNodes();
        vector<Course*> orderedCourses = orderCourses(nodes);
        for (Course* course : orderedCourses) {
            result.push_back(course->getCourseId());
        }
        return result;
    }

    // Build the graph, adding the edge (a, b) if b is dependent on a. Assumes
    // a pair is listed in "course order". The pair (a, b) in dependencies
    // indicates that b depends on a and a must be studied before b.
    Graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph;

        for (int i = 0; i < numCourses; ++i) {
          graph.getOrCreateNode(i);
        }

        for (const vector<int>& prerequisite : prerequisites) {
            graph.addEdge(prerequisite[1], prerequisite[0]);
        }

        return graph;
    }

    // Return a list of courses in a correct course order.
    vector<Course*> orderCourses(vector<Course*> courses) {
        vector<Course*> order(courses.size());
        
        // Add "roots" to the course order first.
        for (size_t toBeProcessed = 0, endOfList = addNonDependent(order, courses, 0); toBeProcessed < order.size(); ++toBeProcessed) {
            Course* current = order[toBeProcessed];
	    // Circular dependency since there are no remaining projects with
            // zero dependencies.
            if (!current) return {};
            
            // Remove the current as dependency
            vector<Course*> children = current->getChildren();
            for (Course* child : children) child->decrementDependencies();

            // Add children with no courses depending on them.
            endOfList = addNonDependent(order, children, endOfList);
        }

        return order;
    }

    /* A helper function to insert projects with zero dependencies into the
     * order array, starting at index offset */
    size_t addNonDependent(vector<Course*>& order, vector<Course*> courses, size_t offset) {
        for (Course* course : courses) {
            if (!course->getNumberOfDependencies()) {
                order[offset++] = course;
            }
        }
        return offset;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites1{{1,0}};
    cout << "TEST 1: ";
    for (int course : s.findOrder(2, prerequisites1)) {
        cout << course << " ";
    }
    cout << endl;
    return 0;
}

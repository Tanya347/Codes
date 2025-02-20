/*

questions[
{id:1, tags: ["MAC", "VSCODE"]},
{id:2, tags: ["PY", "AI"]}
{id:3, tags: ["JAVA", "OS"]}
{id:4, tags: ["PY", "NW"]}
]


Volunteer[
{id: "1", tags:["PY",""NW], name: "A"},
{id: "2", tags:["AI"], name: "B"},
{id: "3", tags:["JAVA","NW], name: "C"},
{id: "4", tags:["JAVA","NW"], name: "D"}
]


Assign question to volunteers such that each question is assigned to at most one volunteer based on tags match.
One volunteer can take at most one question and maximise the question assigned to volunteer.


for this example
A can take question 4(PY match)
B can take question 2(AI match)
C can take question 3(Java match)
Question one no one can take as not match.

*/


class Volunteer {
public:
    int id;
    string name;
    unordered_set<string> tags;

    Volunteer(int id, string name, unordered_set<string> tags)
        : id(id), name(name), tags(tags) {}
};

class Question {
public:
    int id;
    unordered_set<string> tags;

    Question(int id, unordered_set<string> tags)
        : id(id), tags(tags) {}
};

bool isTagMatching(const Question& question, const Volunteer& volunteer) {
    for (const string& tag : question.tags) {
        if (volunteer.tags.find(tag) != volunteer.tags.end()) {
            return true;
        }
    }
    return false;
}

bool f(int question, vector<Question>& questions, vector<Volunteer>& volunteers, 
       vector<int>& visited, vector<int>& connections) {
    
    for (int volunteer = 0; volunteer < volunteers.size(); volunteer++) {
        if (isTagMatching(questions[question], volunteers[volunteer]) && visited[volunteer] == 0) {
            visited[volunteer] = 1;
          // If the volunteer is already assigned a question, we try to push that question to another volunteer using recursion.
            if (connections[volunteer] == -1 ||
                f(connections[volunteer], questions, volunteers, visited, connections)) {
                connections[volunteer] = question;
                return true;
            }
        }
    }
    return false;
}

void assignQuestion(vector<Question>& questions, vector<Volunteer>& volunteers) {
    int row = questions.size();
    int col = volunteers.size();
    vector<int> connections(col, -1);

    for (int question = 0; question < row; question++) {
        vector<int> visited(col, 0);
        f(question, questions, volunteers, visited, connections);
    }

    for (int i = 0; i < connections.size(); i++) {
        if (connections[i] != -1) {
            cout << volunteers[i].name << " can take question " << questions[connections[i]].id << endl;
        }
    }
}

int main() {
    vector<Volunteer> volunteers = {
        {1, "A", {"PY", "NW"}},
        {2, "B", {"AI"}},
        {3, "C", {"JAVA", "NW"}},
        {4, "D", {"JAVA", "NW"}}
    };

    vector<Question> questions = {
        {1, {"MAC", "VSCODE"}},
        {2, {"PY", "AI"}},
        {3, {"JAVA", "OS"}},
        {4, {"PY", "NW"}}
    };

    assignQuestion(questions, volunteers);

    return 0;
}

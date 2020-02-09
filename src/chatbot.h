#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // Task 2 copy constructor
    ChatBot(const ChatBot &source);
    
    // Task 2 copy assignment operator
    ChatBot &operator=(const ChatBot &source);

    // Task 2 move constructor
    ChatBot(ChatBot &&source);

    // Task 2 move assignment operator
    ChatBot &operator=(ChatBot &&source); 

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    void SetImageHandle(wxBitmap * imageHandle) { _image = imageHandle;}
    ChatLogic * GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }
    GraphNode *GetRootNode() { return _rootNode; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
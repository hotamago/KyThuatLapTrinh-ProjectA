// Description: Main file of the program

// Include open libraries
#include <bits/stdc++.h>
#include "libs/rapidxml-1.13/rapidxml_utils.hpp"

// Include module
#include "module/ConfigReader.h"

// Include funplus
#include "funplus/String.h"
#include "funplus/XML.h"

// Include entity
#include "entity/Edge.h"

// Include debug
#include "debug/Debugger.h"
#include "debug/Vector.h"

// Include namespace
using namespace std;

// Global variables
map<string, string> config;

// Function support
bool checkNineLane(rapidxml::xml_node<char> *node)
{
    if (node == nullptr)
        return false;
    if (funplus::XML::size(node) > 1)
        return false;
    auto attNode = node->first_attribute("disallow");
    if (attNode == nullptr)
        return false;
    string attNodeValue = attNode->value();
    if (attNodeValue != "pedestrian")
        return false;
    return true;
}

bool checkNineEdge(rapidxml::xml_node<char> *node)
{
    if (node == nullptr)
        return false;
    if (node->first_attribute("from") == nullptr)
        return false;
    if (node->first_attribute("to") == nullptr)
        return false;
    return true;
}

// Main function
int main()
{
    // Initialize debugger
    debug::Debugger *debugger = new debug::Debugger();

    // Read configuration
    module::ConfigReader configReader;
    config = configReader.Read();

    // Read XML file
    rapidxml::file<> xmlFile(config["XML_FILE"].c_str()); // Default template is char
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    auto netXML = doc.first_node("net");

    // Read edge and process
    auto edgeRaw = netXML->first_node("edge");
    while (edgeRaw != nullptr)
    {
        // Get shape from lane
        auto laneRaw = edgeRaw->last_node("lane");

        if (!checkNineLane(laneRaw))
        {
            edgeRaw = edgeRaw->next_sibling("edge");
            continue;
        }

        string shapeRaw = laneRaw->first_attribute("shape")->value();
        vector<string> shapeRawSplit = funplus::String::split(shapeRaw, ' ');

        entity::Shape *shape = new entity::Shape(
            new entity::Point(shapeRawSplit[0]),
            new entity::Point(shapeRawSplit[1]),
            atof(laneRaw->first_attribute("length")->value()),
            laneRaw->first_attribute("id")->value());

        // Build edge
        if (!checkNineEdge(edgeRaw))
        {
            edgeRaw = edgeRaw->next_sibling("edge");
            continue;
        }

        entity::Edge *edge = new entity::Edge(
            edgeRaw->first_attribute("id")->value(),
            edgeRaw->first_attribute("from")->value(),
            edgeRaw->first_attribute("to")->value(),
            shape);

        if (!edge->checkNiceEdge())
        {
            edgeRaw = edgeRaw->next_sibling("edge");
            continue;
        }

        cout << *edge << endl;

        edgeRaw = edgeRaw->next_sibling("edge");
    }

    return 0;
}
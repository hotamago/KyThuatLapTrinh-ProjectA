#pragma once
#include "../libs/rapidxml-1.13/rapidxml_utils.hpp"
#include <vector>
using namespace std;

namespace funplus
{
    namespace XML
    {
        int size(rapidxml::xml_node<char> *node)
        {
            int res = 0;
            while (node != nullptr)
            {
                res++;
                node = node->next_sibling();
            }
            return res;
        }
        int sizeChilds(rapidxml::xml_node<char> *node, char *name)
        {
            int res = 0;
            node = node->first_node(name);
            while (node != nullptr)
            {
                res++;
                node = node->next_sibling(name);
            }
            return res;
        }
        vector<rapidxml::xml_node<char> *> getNodes(rapidxml::xml_node<char> *node)
        {
            vector<rapidxml::xml_node<char> *> res;
            while (node != nullptr)
            {
                res.push_back(node);
                node = node->next_sibling();
            }
            return res;
        }
    }
}
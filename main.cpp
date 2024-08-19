#include <map>
#include "csmenugen/csmenugen.h"

std::vector<std::string> menuKeys {"kp_ins", "kp_end", "kp_downarrow", "kp_pgdn", "kp_leftarrow", "kp_5", "kp_rightarrow", "kp_home", "kp_uparrow", "kp_pgup"};

class MenuKeys
{
    static std::map<int, std::string>& GetMap()
    {
        static std::map<int, std::string> value
        {
            { 0, "kp_ins" },
            { 1, "kp_end" },
            { 2, "kp_downarrow" },
            { 3, "kp_pgdn", },
            { 4, "kp_leftarrow" },
            { 5, "kp_5" },
            { 6, "kp_rightarrow" },
            { 7, "kp_home" },
            { 8, "kp_uparrow" },
            { 9, "kp_pgup" }
        };
        
        return value;
    }
public:
    std::string operator[](int i) const
    {
        if(!GetMap().count(i)) throw "no key in map";
        return GetMap()[i];
    }
    
    ssize_t size() const
    { return GetMap().size(); }
};

int main(int argc, char* argv[])
{    
    Menu<MenuKeys>
    {
        {
            1,
            {
                { 0, {""} },//no action returns to root menu
                { 1, {"alias buysec glock"} },
                { 2, {"alias buysec usp"} },
                { 3, {"alias buysec p228"} },
                { 4, {"alias buysec deagle"} },
                { 5, {"alias buysec elites" } }
            }
        },
        {
            2,
            {
                { 0, {""} },
                { 1, {"alias buypri m3"} },
                { 2, {"alias buypri autoshotgun"} }
            }
        },
        {
            3,
            {
                { 0, {""} },
                { 1, {"alias buypri mac10"} },
                { 2, {"alias buypri mp5"} },
                { 3, {"alias buypri ump45"} },
                { 4, {"alias buypri p90"} }
            }
        },
        {
            4,
            {
                { 0, {""} },
                { 1, {"alias buypri famas;galil;" } },
                { 2, {"alias buypri \"ak47;m4a1;\"" } },
                { 3, {"alias buypri scout" } },
                { 4, {"alias buypri \"sg552;aug;\"" } },
                { 5, {"alias buypri awp"} },
                { 6, {"alias buypri \"d3aul;krieg550;\"" } }
            }
        },
        {
            5,
            {
                { 0, {""} },
                { 1, {"alias buypri m249"} }
            }
        },
        {
            8,
            {
                { 0, {""} },
                { 1, {"alias armor vest"} },
                { 2, {"alias armor vesthelm"} }
            }
        }
    }.Compile("menu", "menu");
    return 0;
}
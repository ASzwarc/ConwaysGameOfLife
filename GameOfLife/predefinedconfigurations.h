#ifndef PREDEFINEDCONFIGURATIONS_H
#define PREDEFINEDCONFIGURATIONS_H
#include <vector>
#include <utility>
#include <string>

struct Configuration
{
    enum class Type
    {
        Glider,
        Exploder,
        Tumbler
    };

    Configuration();
    virtual std::string getName();
    std::vector<std::pair<int, int>> activeCells_;
};

struct GliderConfiguration: public Configuration
{
    /*
     * xxx
     * xoo
     * oxo
     */
    GliderConfiguration();
    std::string getName() override;
};

struct ExploderConfiguration: public Configuration
{
    /*
     * oxo
     * xxx
     * xox
     * oxo
     */
    ExploderConfiguration();
    std::string getName() override;
};

struct TumblerConfiguration: public Configuration
{
    /*
     * oxxoxxo
     * oxxoxxo
     * ooxoxoo
     * xoxoxox
     * xoxoxox
     * xxoooxx
     */
    TumblerConfiguration();
    std::string getName() override;
};

#endif // PREDEFINEDCONFIGURATIONS_H

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
/* This will be done later when needed
struct ExploderConfiguration: public PredefinedConfiguration
{
    ExploderConfiguration();
};

struct TumblerConfiguration: public PredefinedConfiguration
{
    TumblerConfiguration();
};
*/
#endif // PREDEFINEDCONFIGURATIONS_H

#ifndef PREDEFINEDCONFIGURATIONS_H
#define PREDEFINEDCONFIGURATIONS_H
#include <vector>
#include <utility>

struct Configuration
{
    enum class Type
    {
        Glider,
        Exploder,
        Tumbler
    };

    Configuration();
    std::vector<std::pair<int, int>> activeCells_;
};

struct GliderConfiguration: public Configuration
{
    GliderConfiguration();
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

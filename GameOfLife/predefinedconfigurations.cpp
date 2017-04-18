#include "predefinedconfigurations.h"
#include <QDebug>

Configuration::Configuration()
{
}

std::string Configuration::getName()
{
    return "Default";
}

GliderConfiguration::GliderConfiguration()
{
    activeCells_.push_back({3, 4});
    activeCells_.push_back({4, 4});
    activeCells_.push_back({5, 4});
    activeCells_.push_back({3, 5});
    activeCells_.push_back({4, 6});
    qDebug() << "Glider was created!";
}

std::string GliderConfiguration::getName()
{
    return "Glider";
}

ExploderConfiguration::ExploderConfiguration()
{
    activeCells_.push_back({3, 4});
    activeCells_.push_back({4, 3});
    activeCells_.push_back({4, 5});
    activeCells_.push_back({5, 3});
    activeCells_.push_back({5, 5});
    activeCells_.push_back({6, 4});
    qDebug() << "Exploder was created!";
}

std::string ExploderConfiguration::getName()
{
    return "Exploder";
}

TumblerConfiguration::TumblerConfiguration()
{
    activeCells_.push_back({2, 2});
    activeCells_.push_back({2, 3});
    activeCells_.push_back({2, 5});
    activeCells_.push_back({2, 6});
    activeCells_.push_back({3, 2});
    activeCells_.push_back({3, 3});
    activeCells_.push_back({3, 5});
    activeCells_.push_back({3, 6});
    activeCells_.push_back({4, 3});
    activeCells_.push_back({4, 5});
    activeCells_.push_back({5, 1});
    activeCells_.push_back({5, 3});
    activeCells_.push_back({5, 5});
    activeCells_.push_back({5, 7});
    activeCells_.push_back({6, 1});
    activeCells_.push_back({6, 3});
    activeCells_.push_back({6, 5});
    activeCells_.push_back({6, 7});
    activeCells_.push_back({7, 1});
    activeCells_.push_back({7, 2});
    activeCells_.push_back({7, 6});
    activeCells_.push_back({7, 7});
    qDebug() << "Tumbler was created!";
}

std::string TumblerConfiguration::getName()
{
    return "Tumbler";
}

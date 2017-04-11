#include "predefinedconfigurations.h"
#include <QDebug>

PredefinedConfigurations::PredefinedConfigurations()
{

}

GliderConfiguration::GliderConfiguration():
    PredefinedConfiguration(),
    activeCells_{{3, 3}, {3, 4}, {3, 5},
                 {4, 3}, {5, 4}}
{
    qDebug() << "Glider was created!";
}

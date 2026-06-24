import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Window {
    // Window properties
    id: root
    width: 1920
    height: 1080
    visible: true
    color: backColor
    title: qsTr("Fit tracker")

    Column
    {
        spacing: 10

        Text
        {
            text: mainPage.displayedDay.date
        }

        Text
        {
            text: "Calories: "
                + mainPage.displayedDay.totalCalories
        }

        Text
        {
            text: "Protein: "
                + mainPage.displayedDay.totalProtein
        }

        Button
        {
            text: "Previous day"

            onClicked:
                mainPage.loadPreviousDay()
        }

        Button
        {
            text: "Next day"

            onClicked:
                mainPage.loadNextDay()
        }

        ListView
        {
            width: 400
            height: 300

            model: mainPage.displayedDay.meals

            delegate: Column
            {
                required property var meal

                Text
                {
                    text: meal.name
                }

                Text
                {
                    text: meal.calories + " kcal"
                }

                ListView
                {
                    width: 300
                    height: contentHeight

                    model: meal.foods

                    delegate: Row
                    {
                        spacing: 10

                        Text
                        {
                            text: name
                        }

                        Text
                        {
                            text: calories + " kcal"
                        }
                    }
                }
            }
        }
    }
}
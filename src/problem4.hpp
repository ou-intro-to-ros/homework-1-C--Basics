#include <string>
#include <vector>
#include <stdexcept>

// =============================================================
// Problem 4 - Robot Inventory (Class-Based, with Pointers/Refs)
// =============================================================
//
// DO NOT MODIFY THIS FILE.
// You will implement everything declared here inside problem_4.cpp.
// The autograder compiles YOUR problem_4.cpp against THIS header
// (a fresh copy, not the one in your repo), so changing signatures,
// names, or this file will not help you pass the tests.
//
// Read every comment below carefully -- it specifies EXACTLY what
// each function must do, including edge cases and what to throw.

/**
 * Robot
 * -----
 * Represents a single robot with a name and a cost.
 */
class Robot {
public:
    /**
     * Construct a Robot.
     * @throws std::invalid_argument if name is empty ("")
     * @throws std::invalid_argument if cost is negative (< 0.0f)
     */
    Robot(const std::string& name, float cost);

    // Returns the robot's name.
    std::string getName() const;

    // Returns the robot's cost.
    float getCost() const;

    /**
     * Updates the robot's name.
     * @throws std::invalid_argument if name is empty ("")
     */
    void setName(const std::string& name);

    /**
     * Updates the robot's cost.
     * @throws std::invalid_argument if cost is negative (< 0.0f)
     */
    void setCost(float cost);

    /**
     * Prints the robot in this exact format (no extra blank lines):
     *   Name: <name>
     *   Cost: $<cost>
     */
    void print() const;

private:
    std::string name_;
    float cost_;
};

/**
 * RobotInventory
 * --------------
 * Owns a collection of Robots and reports on them.
 */
class RobotInventory {
public:
    /**
     * Constructs a Robot from (name, cost) and adds it to the inventory.
     * @throws std::invalid_argument propagated from the Robot constructor
     *         if name is empty or cost is negative. If it throws, the
     *         robot must NOT be added to the inventory.
     */
    void addRobot(const std::string& name, float cost);

    /**
     * Prints "Robot Inventory:" then a "-------------------------" line,
     * then calls print() on every robot in insertion order, printing a
     * "-------------------------" separator after each robot.
     * If the inventory is empty, prints only:
     *   Robot Inventory:
     *   -------------------------
     */
    void printAll() const;

    /**
     * Returns a pointer to the most expensive robot in the inventory.
     * If there is a tie, return the one added FIRST.
     * @returns nullptr if the inventory is empty.
     */
    const Robot* findMostExpensiveRobot() const;

    /**
     * Returns the average cost of all robots in the inventory.
     * @returns 0.0 if the inventory is empty.
     */
    double getAverageCost() const;

    // Returns the number of robots currently in the inventory.
    size_t size() const;

private:
    std::vector<Robot> robots_;
};

#endif  // PROBLEM_4_HPP

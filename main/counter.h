#include <thread> // std::thread

/**
 * @brief Class for count impulses on GPIO
 * 
 */
class Counter
{
public:
    /**
     * @brief Construct a new Counter object
     * 
     * @param gpioPin 
     */
    Counter(const int gpioPin);

    /**
     * @brief Get the Value object
     * 
     * @return long 
     */
    long getValue();

    /**
     * @brief Update GPIO status and counter
     * 
     */
    void update();

private:
    /**
     * @brief GPIO pin
     * 
     */
    const int _gpioPin;

    /**
     * @brief Previous pin state
     * 
     */
    bool _prevState;

    /**
     * @brief Counts
     * 
     */
    long _value;
};

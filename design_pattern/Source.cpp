//#include <iostream>
//
//// ���� �������̽�
//class Strategy {
//public:
//    virtual void execute() const = 0;
//};
//
//// ��ü���� ���� Ŭ���� 1
//class ConcreteStrategy1 : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing Strategy 1" << std::endl;
//        // ���� ���� 1�� ���� ����
//    }
//};
//
//// ��ü���� ���� Ŭ���� 2
//class ConcreteStrategy2 : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing Strategy 2" << std::endl;
//        // ���� ���� 2�� ���� ����
//    }
//};
//
//// ���ؽ�Ʈ Ŭ����
//class Context {
//private:
//    Strategy* strategy;
//
//public:
//    Context(Strategy* initialStrategy) : strategy(initialStrategy) {}
//
//    void setStrategy(Strategy* newStrategy) {
//        strategy = newStrategy;
//    }
//
//    void executeStrategy() const {
//        strategy->execute();
//    }
//};
//
//int main() {
//    ConcreteStrategy1 strategy1;
//    ConcreteStrategy2 strategy2;
//
//    Context context(&strategy1); // �ʱ� ���� ����
//
//    context.executeStrategy(); // ���� ���� ����
//
//    context.setStrategy(&strategy2); // ���� ����
//    context.executeStrategy(); // ����� ���� ����
//
//    return 0;
//}
//

#include <iostream>
#include <vector>

namespace Observer {
    using ObserverFunction = void(*)(const std::string&);

    static std::vector<ObserverFunction> observers;

    void addObserver(ObserverFunction observer) {
        observers.push_back(observer);
    }

    void removeObserver(ObserverFunction observer) {
        // ���� �ʿ�
    }

    void notifyObservers(const std::string& message) {
        for (const auto& observer : observers) {
            observer(message);
        }
    }
}

int main() {
    Observer::addObserver([](const std::string& message) {
        std::cout << "Observer 1 received message: " << message << std::endl;
        });

    Observer::addObserver([](const std::string& message) {
        std::cout << "Observer 2 received message: " << message << std::endl;
        });

    Observer::notifyObservers("Hello, observers!");

    // �ٸ� ���۵�...

    return 0;
}

//#include <iostream>
//
//// 전략 인터페이스
//class Strategy {
//public:
//    virtual void execute() const = 0;
//};
//
//// 구체적인 전략 클래스 1
//class ConcreteStrategy1 : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing Strategy 1" << std::endl;
//        // 실제 전략 1에 대한 구현
//    }
//};
//
//// 구체적인 전략 클래스 2
//class ConcreteStrategy2 : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing Strategy 2" << std::endl;
//        // 실제 전략 2에 대한 구현
//    }
//};
//
//// 컨텍스트 클래스
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
//    Context context(&strategy1); // 초기 전략 설정
//
//    context.executeStrategy(); // 현재 전략 실행
//
//    context.setStrategy(&strategy2); // 전략 변경
//    context.executeStrategy(); // 변경된 전략 실행
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
        // 구현 필요
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

    // 다른 동작들...

    return 0;
}

cmake_minimum_required(VERSION 2.8)

project(DesignPatterns)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(AbstractFactory source/abstract_factory/abstract_factory.cpp)
add_executable(Builder source/builder/builder.cpp)
add_executable(FactoryMethod source/factory_method/factory_method.cpp)
add_executable(Singleton source/singleton/singleton.cpp)
add_executable(Adapter source/adapter/adapter.cpp)
add_executable(Decorator source/decorator/decorator.cpp)
add_executable(Facade source/facade/facade.cpp)
add_executable(Observer source/observer/observer.cpp)
add_executable(Strategy source/strategy/strategy.cpp)
add_executable(Prototype source/prototype/prototype.cpp)
add_executable(Command source/command/command.cpp)
add_executable(Memento source/memento/memento.cpp)
add_executable(Iterator source/iterator/iterator.cpp)
add_executable(Bridge source/bridge/bridge.cpp)
add_executable(Flyweight source/flyweight/flyweight.cpp)
add_executable(ChainOfResponsibility source/chain_of_responsibility/chain_of_responsibility.cpp)
add_executable(Proxy source/proxy/proxy.cpp)
add_executable(Composite source/composite/composite.cpp)

include_directories(state)
add_executable(State
    source/state/main.cpp
    source/state/music_player.h
    source/state/music_player.cpp
    source/state/music_player_state.h
    source/state/music_player_state.cpp)

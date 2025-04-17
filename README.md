# На пути к познанию C++ и ROS

## Подготовка к работе

### Требования к системе

- Ubuntu 20.04 с ROS Noetic (GCC 9, частично поддерживает стандарт C++17)
- CMake, Git
- catkin tools ([инструкции по установке](https://catkin-tools.readthedocs.io/en/latest/installing.html))

Проверьте версии компилятора и CMake:
```shell
cmake --version
g++ --version
```

### Клонирование проекта

Склонируйте репозиторий к себе на компьютер (предварителньо рекомендуется сделать fork репозитория):
```shell
git clone <ссылка на репозиторий>
```

## Сборка проекта

Собрать проект можно следующей командой (из `workspace` и вложенных директорий):
```shell
catkin build
```

Собрать конкретный пакет:
```shell
catkin build ros_cpp_tutorials
```

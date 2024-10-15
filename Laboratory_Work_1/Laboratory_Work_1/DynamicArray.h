
//! \brief Структура динамического массива.
struct DynamicArray
{
private:
    //! \brief Размер массива.
    int _size;

    //! \brief Вместимость массива.
    int _capacity;

    //! \brief Массив.
    int* _array;

    //! \brief Фактор роста.
    const int _growthFactor = 2;

    //! \brief Вспомогательная функция для расширения массива.
    void _resize(int newCapacity);

public:
    //! \brief Конструктор по умолчанию.
    DynamicArray();

    //! \brief Конструктор с заданным начальным размером.
    DynamicArray(int initialCapacity);

    //! \brief Деструктор.
    ~DynamicArray();

    //! \brief Возвращает размер массива.
    //! \return Размер массива.
    int GetSize();

    //! \brief Возвращает вместимость массива.
    //! \return Вместимость массива.
    int GetCapacity();

    //! \brief Возвращает массив.
    //! \return Массив.
    int* GetArray();
    
    //! \brief Добавляет элемент в массив.
    //! \param index Индекс элемента, куда нужно добавить элемент.
    //! \param value Значение элемента.
    void AddElement(int index, int value);

    //! \brief Удаляет элемент массива по передаваемому индексу.
    //! \param index Индекс элемента, который нужно удалить.
    void RemoveByIndex(int index);

    //! \brief Удаляет значение элемента по его передаваемому значению.
    //! \param value Посылаемое значение, которое нужно удалить.
    void RemoveByValue(int value);

    //! \brief Возвращает элемент по индексу.
    //! \param index Индекс, по которому нужно получить значение.
    //! \return Возвращает значение, которое находится под индексом.
    int GetElement(int index);

    //! \brief Сортирует массив методом Shaker Sort.
    void SortArray();

    //! \brief Линейный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    void LinerSearch(int value);

    //! \brief Бинарный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    void BinarySearch(int value);
};
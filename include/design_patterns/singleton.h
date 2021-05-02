namespace design_patterns {
class MySingleton {
  public:
    static MySingleton &getInstance();
    MySingleton(MySingleton &) = delete;
    MySingleton(MySingleton &&) = delete;
    MySingleton &operator=(MySingleton &) = delete;
    MySingleton &operator=(MySingleton &&) = delete;

  private:
    MySingleton();
};
} // namespace design_patterns
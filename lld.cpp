/*Design patterns*/

/*Behavioural*/
/*Observer design pattern*/
class Observer{   
  public: 
  virtual void update(int value) = 0;
};
class Subject{
  int m_value;
  list<Observer*> views;
  public:
    void attach(Observer *obs){views.push_back(obs);} //build list of observers
    void set_val(int value){m_value = value; notify();}
    void notify() //call some functionality of list of observers
    { list<Observer*>::iterator it = views.begin();
      while(it != views.end()){(*it)->update(m_value);++it;}
    }
};
class DivObserver: public Observer
{   int m_div;
  public:
    DivObserver(Subject *model, int div){model->attach(this);m_div = div;}//register this observer to subject
     void update(int v){cout<<v<<" div "<<m_div<<" is "<<v/m_div<<'\n';}//operation to be performed
};
class ModObserver: public Observer
{   int m_mod;
  public:
    ModObserver(Subject *model, int mod){model->attach(this);m_mod = mod;}
    void update(int v){cout<<v <<" mod "<<m_mod<<" is "<<v % m_mod<<'\n';}
};
int main()
{ 
  Subject subj;
  DivObserver divObs1(&subj, 4);DivObserver divObs2(&subj, 3);ModObserver modObs3(&subj, 3);
  subj.set_val(14);
}


/*
************************************************************************************************************
************************************************************************************************************
*/
/*state design pattern*/
interface State {
    void pull(CeilingFanPullChain wrapper);
}
class CeilingFanPullChain {
    private State currentState;//state class object as data member
    public CeilingFanPullChain() {currentState = new Off();}
    public void set_state(State s) {currentState = s;}//setter function
    public void pull() {currentState.pull(this);}//call different state operation via this fucntion
}
class Off implements State {
    public void pull(CeilingFanPullChain wrapper) {
        wrapper.set_state(new Low());System.out.println("low speed");
    }
}
class Low implements State {
    public void pull(CeilingFanPullChain wrapper) {
        wrapper.set_state(new Medium());System.out.println("medium speed");
    }
}
class Medium implements State {
    public void pull(CeilingFanPullChain wrapper) {
        wrapper.set_state(new High());System.out.println("high speed");
    }
}
class High implements State {
    public void pull(CeilingFanPullChain wrapper) {
        wrapper.set_state(new Off());System.out.println("turning off");
    }
}
public class StateDemo {
    public static void main(String[] args) {
        CeilingFanPullChain chain = new CeilingFanPullChain();
        while (true) {
            System.out.print("Press ENTER");getLine();
            chain.pull();
        }
    }
}



/*
************************************************************************************************************
************************************************************************************************************
*/
/*chain of responsibility design pattern*/

#include <iostream>
#include <string>

// Handler Interface
class AuthenticationHandler {
public:
    virtual void
    setNextHandler(AuthenticationHandler* handler) = 0;
    virtual void handleRequest(const std::string& request) = 0;
};
// Concrete Handlers
class UsernamePasswordHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;
public:
    void setNextHandler(AuthenticationHandler* handler) override {nextHandler = handler;}
    void handleRequest(const std::string& request) override {
        if (request == "username_password") std::cout << "Authenticated using username and password."<< std::endl;
        else if (nextHandler != nullptr) nextHandler->handleRequest(request);
        else std::cout << "Invalid authentication method."<< std::endl;
    }
};

class OAuthHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;
public:
    void setNextHandler(AuthenticationHandler* handler) override {nextHandler = handler;}
    void handleRequest(const std::string& request) override {
        if (request == "oauth_token") std::cout << "Authenticated using OAuth token."<< std::endl;
        else if (nextHandler != nullptr) nextHandler->handleRequest(request);
        else std::cout << "Invalid authentication method."<< std::endl;
    }
};
// Client
int main()
{
    AuthenticationHandler* usernamePasswordHandler= new UsernamePasswordHandler();
    AuthenticationHandler* oauthHandler = new OAuthHandler();
    // Set up the chain
    usernamePasswordHandler->setNextHandler(oauthHandler);
    // Handling authentication requests
    usernamePasswordHandler->handleRequest("oauth_token");
    usernamePasswordHandler->handleRequest("username_password");
    usernamePasswordHandler->handleRequest("invalid_method");
    delete usernamePasswordHandler;
    delete oauthHandler;
    return 0;
}

/*
************************************************************************************************************
************************************************************************************************************
*/
/*Strategy design pattern*/
#include <iostream>
#include <memory> // For std::unique_ptr

// Strategy Interface
class SortingStrategy {
public:
    virtual void sort(int arr[], int size) = 0;
    virtual ~SortingStrategy() = default;
};

// Concrete Strategy A: Bubble Sort
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Sorting using Bubble Sort" << std::endl;
        // Bubble sort implementation
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

// Concrete Strategy B: Quick Sort
class QuickSortStrategy : public SortingStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Sorting using Quick Sort" << std::endl;
        // Quick sort implementation (simplified for example)
        if (size > 1) {
            // ... actual quick sort logic
        }
    }
};

// Context
class Sorter {
private:
    std::unique_ptr<SortingStrategy> strategy_;

public:
    void setStrategy(std::unique_ptr<SortingStrategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void performSort(int arr[], int size) {
        if (strategy_) {
            strategy_->sort(arr, size);
        } else {
            std::cout << "No sorting strategy set." << std::endl;
        }
    }
};

// Client Code
int main() {
    Sorter sorter;
    int data[] = {5, 2, 8, 1, 9};
    int size = sizeof(data) / sizeof(data[0]);

    // Use Bubble Sort
    sorter.setStrategy(std::make_unique<BubbleSortStrategy>());
    sorter.performSort(data, size);

    // Change to Quick Sort at runtime
    sorter.setStrategy(std::make_unique<QuickSortStrategy>());
    sorter.performSort(data, size);

    return 0;
}

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

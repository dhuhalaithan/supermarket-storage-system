#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define max 100
bool compare(string s1,string s2) //to check if two strings are equal
{
	if(s1==s2)
		return true;
	else 
		return false;
}
struct product //a struct for product details
{
	string p_name;
	string pm;
	int price;
	
	void GetD() //method to input product
	{
		cout<<"Enter product name: ";
		getline(cin>>ws, p_name);
		cout<<"Enter product price: ";
		cin>>price;
		cout<<"Enter country of manufacture: ";
		getline(cin>>ws,pm);
	}
	void display() //method to display stored product
	{
	   cout<<"product name: " <<p_name;
	   cout<<endl;
	   cout<<"product price: " <<price;
	   cout<<endl;
	   cout<<"product country of manufacture: "<<pm;
	   cout<<endl;
	}
};

struct Stack
{
	product Storage[max];
	int top;
}storage;
void push(product pro)
{
	if(storage.top==max-1)
	{
		cout<<"storage is full, throw expired products to add new products\n";
	}
	
	else
	{
		storage.top++;
		storage.Storage[storage.top] = pro;
	}
}

product pop()
{
	product pro;
	if(storage.top==-1)
	{
		cout<<"no products in the storage, must contact store's suppliers\n";
	}
	
	else
	{
		pro = storage.Storage[storage.top];
		storage.top--;
	}
	return pro;
}

product arrayproduct[1000];
int pcount=0;
struct location //a struct for location details
{
	string section;
	int aisle;
	int shelf;
	product products[1000];
	int loc_p_count=0;
	void GetD() //method to input location
	{
		cout<<"Enter product's section name: ";
		getline(cin>>ws,section);
		cout<<"Enter product's aisle number: ";
		cin>>aisle;
		cout<<"Enter product's shelf number: ";
		cin>>shelf;
		cout<<endl;
	}
	void display() //method to display stored location
	{
	   cout<<"Product's section name: " <<section;
	   cout<<endl;
	   cout<<"Product's aisle number: " <<aisle;
	   cout<<endl;
	   cout<<"Product's shelf number: " <<shelf;
	   cout<<endl;
	   for(int i=0;i<loc_p_count;i++)
	   {
	       cout<<"product name: "<<products[i].p_name;
	       cout<<endl;
	       cout<<"product price: "<<products[i].price;
	       cout<<endl;
	       cout<<"product country of manufacture: "<<products[i].pm;
	       cout<<endl;
	   }
	}
	
	void add_product() //method to assign product to location
	{
	    string product_name,country;
	    
	    for(int i=0;i<pcount;i++)
	    {
		
	       if(products[i].p_name==""&&products[i].pm=="")
			{
				cout<<"Enter product name: ";
	            getline(cin>>ws,product_name);
	            cout<<"Enter product's country of manufacture: ";
	            getline(cin>>ws,country);
	            cout<<endl;
	            break;
	        }
	        else
	        {
	        	cout<<"Location has another product!";
	        	break;
			}
		}        
	    for(int i=0;i<loc_p_count;i++)
		{
	        if(product_name==products[i].p_name&&country==products[i].pm)
			{
	            cout<<endl<<"product already assigned to location"<<endl;
	            return;
	        }
	    }
	    bool found=false;
	    for(int i=0;i<pcount;++i)
		{
	        if(product_name==arrayproduct[i].p_name&&country==arrayproduct[i].pm)
			{
	            products[loc_p_count]=arrayproduct[i];
	            found=true;
	            break;
	        }
	    }
	    if(found)
		{
	        cout<<"Assigned product to location"<<endl;
	        loc_p_count++;
	    }
	    else
	        cout<<"Can't add product!"<<endl;
	}

    void delete_product() //method to delete product
	{
    	string product_name,country;
    	int counter=0;
    	cout<<"Enter product name: ";
    	getline(cin>>ws,product_name);
    	cout<<"Enter product's country: ";
    	getline(cin>>ws,country);
    	bool found=false;
    	for(int i=0;i<loc_p_count;i++){
    		if(compare(product_name,arrayproduct[i].p_name)==true&&compare(country,arrayproduct[i].pm)==true)
			{
    			counter++;
				arrayproduct[i].p_name="";
				arrayproduct[i].price=0;
				arrayproduct[i].pm="";
				found=1;
				break;
			}
		}
		if(found)
		{
			cout<<"Removed product from location"<<endl;
            loc_p_count--;
		}
		if(found==0)
		{
			cout<<"Product name not found"<<endl;
		}
	}
};
location location_array[1000];
int location_count=0;


int main()
{
	storage.top = -1;
	int choice, locationaisle, locationshelf;
    string product_name, locationsection, country;
    fstream fsOut;
    fsOut.open("project.txt");
	do //the start of the system
	{
			
    cout<<"\n";
	cout<<"                                            \n";
	cout<<"         supermarket storage system                \n";
	cout<<"                                              \n";
	cout<<"___________________________________________\n\n";
	cout<<" 1) Add product.\n";
	cout<<" 2) Add location.\n";
	cout<<" 3) Display all locations.\n";
	cout<<" 4) Display all products.\n";
	cout<<" 5) Update product details.\n";
	cout<<" 6) Update location details.\n";
	cout<<" 7) Delete product details .\n";
	cout<<" 8) Delete location details .\n";
	cout<<" 9) Assigen product to location.\n";
	cout<<" 10) Remove product from location.\n";
	cout<<" 11) Search location \n";
	cout<<" 12) Search product. \n";
	cout<<" 13) Exit.\n";
	cout<<"______________________________________________\n";
     cout<<endl;
     cout<<"Enter your choice: ";
     cin>>choice;
     cout<<endl;
     switch(choice) //switch to evaluate user choice input
	 {
	 	case 1:
	 		{
	 			arrayproduct[pcount].GetD();
	 			push(arrayproduct[pcount]);
	 			pcount++;
	 			break;
			}
			
		case 2:
			{
				location_array[location_count].GetD();
				location_count++;
				break;
			}
		
		case 3:
			{
				for(int i=0; i < location_count; i++)
				{
					cout<<endl;
					location_array[i].display();
					cout<<endl;
				}
				break;
			}
		
		case 4:
			{
				for(int i = storage.top; i>=0;i--)
				{
					cout<<endl;
					product product = pop();
					product.display();
					cout<<endl;
				}
				break;
			}
			
		case 5:
			{
				string product_name;
				cout<<"Enter product name: ";
				getline(cin>>ws,product_name);
				cout<<"Enter product country of manufacture: ";
				getline(cin>>ws,country);
				cout<<endl;
				for(int i=0;i<pcount;i++)
				{
					if(compare(product_name,arrayproduct[i].p_name)==true&&compare(country,arrayproduct[i].pm)==true)
					{
						arrayproduct[i].GetD();
						break;
					}
				}
				break;
			}
			
		case 6:
			{
				int locationshelf;
				cout<<"Enter product's section name: ";
				getline(cin>>ws,locationsection);
				cout<<"Enter product's aisle number: ";
				cin>>locationaisle;
				cout<<"Enter product's section number: ";
				cin>>locationshelf;
				cout<<endl;
				for(int i = 0; i < pcount; i ++)
				{
					if(locationshelf==location_array[i].shelf&&locationaisle==location_array[i].aisle&&locationsection==location_array[i].section)
					{
						location_array[i].GetD();
						break;
					}
				}
				break;
			}
			
		case 7:
			{
				cout<<"Enter product name: ";
				getline(cin>>ws,product_name);
				cout<<"Enter country of manufacture: ";
				getline(cin,country);
				cout<<endl;
				for(int i = 0; i<pcount; i++)
				{
					if(compare(product_name,arrayproduct[i].p_name)==true&&compare(country,arrayproduct[i].pm)==true)
					{
						for(int j=i;j<pcount;j++)
						{
							arrayproduct[j]=arrayproduct[j+1];
						}
						
						cout<<"Product has been deleted!";
						pcount--;
						cout<<endl;
						break;
					}
				}
				break;
			}
			
		case 8:
			{
				cout<<"Enter product's section: ";
				cin>>locationsection;
				cout<<"Enter product's aisle: ";
				cin>>locationaisle;
				cout<<"Enter product's shelf: ";
				cin>>locationshelf;
				cout<<endl;
				for(int i = 0; i<location_count;i++)
				{
					if(locationshelf==location_array[i].shelf&&locationaisle==location_array[i].aisle&&locationsection==location_array[i].section)
					{
						for(int j=i;j<location_count;j++)
						{
							location_array[j]=location_array[j+1];
						}
						cout<<"Location has been deleted!";
						location_count--;
						cout<<endl;
						break;
					}
				}
				break;
			}
			
		case 9:
			{
				cout<<"Enter wanted section: ";
				getline(cin>>ws,locationsection);
				cout<<"Enter wanted aisle: ";
				cin>>locationaisle;
				cout<<"Enter wanted shelf: ";
				cin>>locationshelf;
				cout<<endl;
				
				for(int i = 0; i < location_count; i++)
				{
					if(locationshelf==location_array[i].shelf&&locationsection==location_array[i].section&&locationaisle==location_array[i].aisle)
					{
						location_array[i].add_product();
						break;
					}
				}
				int i = 0;
				if(locationshelf!=location_array[i].shelf&&locationaisle!=location_array[i].aisle&&locationsection!=location_array[i].section)
				{
					cout<<"Location not found!";
				}
				break;
			}
			
		case 10:
			{
				cout<<"Enter product's section: ";
				getline(cin>>ws,locationsection);
				cout<<"Enter product's aisle number: ";
				cin>>locationaisle;
				cout<<"Enter product's shelf number: ";
				cin>>locationshelf;
				cout<<endl;
				for(int i=0; i<location_count; i++)
				{
					if(locationshelf==location_array[i].shelf&&locationaisle==location_array[i].aisle&&locationsection==location_array[i].section)
					{
						location_array[i].delete_product();
						break;
					}
				}
				int i =0;
				if(locationshelf!=location_array[i].shelf&&locationaisle!=location_array[i].aisle&&locationsection!=location_array[i].section)
				{
					cout<<"Location not found!"<<endl;
				}
				break;
			}
			
		case 11:
			{
				cout<<"Enter product's section: ";
				getline(cin>>ws,locationsection);
				cout<<"Enter product's aisle: ";
				cin>>locationaisle;
				cout<<"Enter product's shelf: ";
				cin>>locationshelf;
				cout<<endl;
				for(int i = 0; i<location_count;i++)
				{
					if(locationshelf==location_array[i].shelf&&locationaisle==location_array[i].aisle&&locationsection==location_array[i].section)
					{
						location_array[i].display();
						break;
					}
				}
				int i = 0;
				if(locationshelf!=location_array[i].shelf&&locationaisle!=location_array[i].aisle&&locationsection!=location_array[i].section)
				{
					cout<<"No result found!"<<endl;
				}
				break;
			}
			
		case 12:
			{
				string product_name;
				cout<<"Enter product name: ";
				getline(cin>>ws,product_name);
				cout<<"Enter country of manufacture: ";
				getline(cin>>ws,country);
				cout<<endl;
				for(int i = 0; i<pcount;i++)
				{
					if(compare(product_name,arrayproduct[i].p_name)==true&&compare(country,arrayproduct[i].pm)==true)
					{
						arrayproduct[i].display();
						break;
					}
					break;
				}
				int i = 0;
				if(compare(product_name,arrayproduct[i].p_name)!=true||compare(country,arrayproduct[i].pm)!=true)
				{
					cout<<"No result found!"<<endl;
				}
				break;
			}
			
		case 13:
			{
				ofstream fsOut;
                fsOut.open("trying.txt",ios::out);
				fsOut<<"Exiting now!";
				fsOut.close();
				break;
			}
			
		default:
			{
				ofstream fsOut;
				fsOut.open("fromlist.txt",ios::out);
				fsOut<<"Choice must be from the list!"; 
				fsOut.close();
				break;
			}
	 }
	}while(choice!=13); //choice 13 will exit user from program
	fsOut.close();

return 0;
}

// Data Structures HW 1 - Image Processing
// Data Structures HW1 Spring 2022 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


// this function is to replace from the characters X to 0 

void replace(std::vector<std::string> v1, char x, char o, std::string filename)
{
    std::ofstream myfile(filename);

    if(myfile.is_open())
    {
    for(unsigned int i = 0; i < v1.size(); i++) //auto i = s1.begin(); i != s1.end(); ++i)
    {
        //std::cout << *i << " " << std::endl;
        std::string s2 = v1[i];
        std::replace(s2.begin(), s2.end(), x,o); // replace all 'X' to '0'
        
        myfile << s2 << std::endl;
    }

    myfile.close();
        
        
    }
    else std::cerr << "Unable to open file"; // error statement

    
        
}

// this function creates a vector that reads line by line 

void createVect(std::vector<std::vector<char> > &stars, std::vector<std::string> v1)
{   std::vector<char> line;
    for(unsigned int i = 0; i < v1.size(); i++) //auto i = s1.begin(); i != s1.end(); ++i)
    {
        for(unsigned int j = 0; j < v1[i].length(); j++)
        {
            line.push_back(v1[i][j]);

        }
        stars.push_back(line);  
        line.clear(); 
    }



}

// this function is for dilation, it makes the image larger from the original
void dilation(char initial, char newer, std::vector<std::vector<char> > stars, std::vector<std::vector<char> > &updated)  
{
    for(int i = 0; i < stars.size(); i++)
    {   
        std::vector<char> line; // creating a vector of characters for the lines of the text
        for(int j = 0; j < stars[i].size(); j++)
        {
            if(stars[i][j] == newer)
            {
                
                // This if statement is the top left corner
                if(i == 0 && j == 0)
                {
                    if(stars[i+1][j] == initial || stars[i][j+1] == initial)
                    {
                        line.push_back(initial); 
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                
                // This if statement is the top right corner
                else if(i == 0 && j == stars[i].size()-1)
                {
                    if(stars[i+1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }  
                
                // This if statement is the bottom right corner
                else if(i == stars.size()-1 && j == stars[i].size() -1)
                {
                    if(stars[i-1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                } 
                // This if statement is the bottom left corner
                else if(i == 0 && j == stars[i].size() -1)
                {
                    if(stars[i-1][j] == initial || stars[i][j+1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }   
                }
                // This if statement is for the top row
                else if(i == 0)
                {
                    if(stars[i + 1][j] == initial || stars[i][j+1] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }

        
                // This if statement is for the bottom row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }

                }

                // This if statement is for the left row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i+1][j] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                // This if statement is for the right row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j-1] == initial || stars[i+1][j] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                // This if statement is for the left row
                else
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i+1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
            }
            else{
                line.push_back(initial);
            }
        }
        updated.push_back(line);
        line.clear();

    }



}
// this function is for erosion, it makes the image smaller from the original
void erosion(char newer, char initial, std::vector<std::vector<char> > stars, std::vector<std::vector<char> > &updated)  
{
    for(int i = 0; i < stars.size(); i++)
    {   
        std::vector<char> line;
        for(int j = 0; j < stars[i].size(); j++)
        {
            if(stars[i][j] == newer)
            {
                
                // This if statement is the top left corner
                if(i == 0 && j == 0)
                {
                    if(stars[i+1][j] == initial || stars[i][j+1] == initial)
                    {
                        line.push_back(initial); 
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                
                // This if statement is the top right corner
                else if(i == 0 && j == stars[i].size()-1)
                {
                    if(stars[i+1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }  
                
                // This if statement is the bottom right corner
                else if(i == stars.size()-1 && j == stars[i].size() -1)
                {
                    if(stars[i-1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                } 
                // This if statement is the bottom left corner
                else if(i == 0 && j == stars[i].size() -1)
                {
                    if(stars[i-1][j] == initial || stars[i][j+1] == initial)
                    {
                        line.push_back(initial); 
                        
                    }
                    else
                    {
                        line.push_back(newer); 
                    }   
                }
                // This if statement is for the top row
                else if(i == 0)
                {
                    if(stars[i + 1][j] == initial || stars[i][j+1] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }

        
                // This if statement is for the bottom row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }

                }

                // This if statement is for the left row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i+1][j] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                // This if statement is for the right row
                else if(i == stars.size() - 1)
                {
                    if(stars[i - 1][j] == initial || stars[i][j-1] == initial || stars[i+1][j] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
                // This if statement is for the left row
                else
                {
                    if(stars[i - 1][j] == initial || stars[i][j+1] == initial || stars[i+1][j] == initial || stars[i][j-1] == initial)
                    {
                        line.push_back(initial); 

                    }
                    else
                    {
                        line.push_back(newer); 
                    }
                }
            }
            else{
                line.push_back(initial);
            }
        }
        updated.push_back(line);
        line.clear();

    }



}

// this function performs dilation then performs erosion
void closing(char initial, char newer, std::vector<std::vector<char> > stars, std::vector<std::vector<char> > &updated, std::vector<std::vector<char> > &more_updated)
{
    erosion(newer, initial, stars, updated); // calling the erosion function
    dilation(newer, initial, updated, more_updated);
}
// this function performs erosion then dilation

void opening(char initial, char newer, std::vector<std::vector<char> > stars, std::vector<std::vector<char> > &updated, std::vector<std::vector<char> > &more_updated)
{
    dilation(newer, initial, stars, updated);
    erosion(newer, initial, updated, more_updated);
}


// Command Line Arguements

int main(int argc, char* argv[])
{

     // Checking for Error

    std::ifstream in_str(argv[1]);
    std::ofstream out_str(argv[2]);
    std::string type = argv[3];
    char x1 = *argv[4];
    char x2;
    if (argc == 6)
    {
        x2 = *argv[5];
    }

    if(argc != 5 && argc != 6)
    {
        std::cerr << "Incorrect number of arguments." << std::endl;
        std::cout << argc << std::endl;
        exit(1);
    }
    else if(!in_str.good()) 
   {
        std::cerr << "Can't open " << argv[1] << " to read." << std::endl;
        exit(1);
    }
    else if(!out_str.good()) 
    {
        std::cerr << "Can't open " << argv[2] << " to write." << std::endl;
        exit(1);
    }
    

    std::fstream newfile;
    std::vector<std::string> g1;
    std::vector<std::vector<char> > grid;
    std::vector<std::vector<char> > newer_grid;
    std::vector<std::vector<char> > even_newer_grid;
    
    newfile.open(argv[1],std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
    std::string tp;
    while(getline(newfile, tp)) //read data from file object and put it into string.
    { 
        //std::cout << tp << std::endl;" //print the data of the string
        g1.push_back(tp);
    }
      
   }
   newfile.close(); //close the file object.
    
    
    std::cout << type << std::endl;
    if(type == "replace")
    {
        replace(g1,x1,x2,argv[2]);
    }
    else if(type == "dilation")
    {
        std::fstream output_file;
        output_file.open(argv[2]);
        createVect(grid,g1);
        dilation(x1,grid[0][0],grid,newer_grid);
        for(int i = 0; i < newer_grid.size(); i++)
        {
            for(int j = 0; j < newer_grid[i].size(); j++)
            {
                output_file << newer_grid[i][j];
            }
            output_file << std::endl;

        }
        output_file.close();
    }
    else if(type == "erosion")
    {
        std::fstream output_file;
        output_file.open(argv[2]);
        createVect(grid,g1);

        erosion(x1,x2,grid,newer_grid);
        for(int i = 0; i < newer_grid.size(); i++)
        {
            for(int j = 0; j < newer_grid[i].size(); j++)
            {
                output_file << newer_grid[i][j];
            }
            output_file << std::endl;

        }
        output_file.close();
        
    }
    else if(type == "opening")
    {
        std::fstream output_file;
        output_file.open(argv[2]);
        createVect(grid,g1);

        opening(x1,x2,grid,newer_grid,even_newer_grid);
        for(int i = 0; i < even_newer_grid.size(); i++)
        {
            for(int j = 0; j < even_newer_grid[i].size(); j++)
            {
                output_file << even_newer_grid[i][j];
            }
            output_file << std::endl;

        }
    }
    else if(type == "closing")
    {
        std::fstream output_file;
        output_file.open(argv[2]);
        createVect(grid,g1);

        closing(x1,x2,grid,newer_grid,even_newer_grid);
        for(int i = 0; i < even_newer_grid.size(); i++)
        {
            for(int j = 0; j < even_newer_grid[i].size(); j++)
            {
                output_file << even_newer_grid[i][j];
            }
            output_file << std::endl;

        }
    }
    //  else if(type == "closing")
    //  {
    //      std::fstream output_file;
    //      output_file.open(argv[2]);
    //      createVect(grid,g1);

    //      closing(x1,x2,grid,newer_grid,even_newer_grid);
    //      for(int i = 0; i < even_newer_grid.size(); i++)
    //      {
    //          for(int j = 0; j < even_newer_grid[i].size(); j++)
    //          {
    //              output_file << even_newer_grid[i][j];
    //          }
    //          output_file << std::endl;

    //      }
    //      output_file.close();
        
    //  }


    return 0;
}

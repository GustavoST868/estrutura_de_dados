//used libraries
import Fila.Queue;
import Lista.List;
import Pilha.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //loop that keeps the user in the program
        while (true){

            //program options menu
            System.out.println("====================    Menu   ====================");
            System.out.println("Escolha qual estrutura deseja utilizar : ");
            System.out.println("1. Lista");
            System.out.println("2. Pilha");
            System.out.println("3. Fila");
            System.out.println("===================================================");
            Scanner scanner = new Scanner(System.in);
            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option){
                //list
                case 1:
                    System.out.println("====================List Module====================");
                    //standard object of operations
                    List list = new List();
                    String options="";

                    //loop that keeps the user in the module
                    while (!options.equals("s")) {


                        //module options menu
                        System.out.println("Menu de opções:");
                        System.out.println("1. Adicionar");
                        System.out.println("2. Pesquisar");
                        System.out.println("3. Deletar");
                        System.out.println("4. Editar");
                        System.out.println("5. Mostrar");
                        System.out.println("Escolha uma opção:");

                        int options_list = scanner.nextInt();
                        scanner.nextLine();

                        switch (options_list){
                            //add
                            case 1:
                                //get data
                                System.out.println("Informe o dado:");
                                String data = scanner.nextLine();
                                list.addData(data);
                                break;

                            //search
                            case 2:
                                //get data
                                System.out.println("Informe o dado:");
                                String data_search = scanner.nextLine();
                                boolean result = list.search(data_search);
                                if(result){
                                    System.out.println("Dado encontrado");
                                }else {
                                    System.out.println("Dado não encontrado");
                                }
                                break;

                            //delete
                            case 3:
                                //get data
                                System.out.println("Informe o dado:");
                                String data_delete = scanner.nextLine();
                                int index = list.getIndexText(data_delete);
                                list.remove(index);
                                break;

                            //update
                            case 4:
                                //get data
                                System.out.println("Informe o dado a ser editado:");
                                String data_edit = scanner.nextLine();

                                System.out.println("Informe o novo dado:");
                                String data_ = scanner.nextLine();

                                list.edit(data_edit,data_);
                                break;

                            //print
                            case 5:
                                list.print();
                                break;

                            default:
                                System.out.println("Opção inválida");
                        }

                        //ask if want to stay,if not,break the loop
                        System.out.println("Deseja sair deste módulo?[s/n]");
                        options = scanner.nextLine();

                    }
                    System.out.println("===================================================");

                    break;
                    //stack
                case 2:
                    System.out.println("====================Stack Module====================");
                    Stack stack = new Stack();
                    int choice;
                    do {
                        System.out.println("\nMenu:");
                        System.out.println("1. Adicionar elemento à pilha");
                        System.out.println("2. Editar elemento na pilha");
                        System.out.println("3. Remover elemento da pilha");
                        System.out.println("4. Exibir elemento no topo da pilha");
                        System.out.println("5. Exibir todos os elementos da pilha");
                        System.out.println("6. Sair");
                        System.out.print("Escolha uma opção: ");
                        choice = scanner.nextInt();

                        switch (choice) {
                            case 1:
                                System.out.print("Digite o elemento a ser adicionado à pilha: ");
                                scanner.nextLine(); // Consume newline
                                String elementToAdd = scanner.nextLine();
                                stack.addStack(elementToAdd);
                                System.out.println("Elemento adicionado com sucesso!");
                                break;
                            case 2:
                                System.out.print("Digite o elemento a ser editado na pilha: ");
                                scanner.nextLine(); // Consume newline
                                String elementToEdit = scanner.nextLine();
                                System.out.print("Digite o novo valor para o elemento: ");
                                String newElementValue = scanner.nextLine();
                                stack.edit(elementToEdit, newElementValue);
                                System.out.println("Elemento editado com sucesso!");
                                break;
                            case 3:
                                stack.unstack();
                                System.out.println("Elemento removido do topo da pilha!");
                                break;
                            case 4:
                                System.out.println("Elemento no topo da pilha: " + stack.getTop());
                                break;
                            case 5:
                                stack.print();
                                break;
                            case 6:
                                System.out.println("Encerrando o programa.");
                                break;
                            default:
                                System.out.println("Opção inválida. Por favor, escolha novamente.");
                        }
                    } while (choice != 6);

                    System.out.println("====================================================");
                    break;
                case 3:
                    Queue queue = new Queue();
                    System.out.println("====================Queue Module====================");
                    String options_queue="";

                    //loop that keeps the user in the module
                    while (!options_queue.equals("s")) {

                        System.out.println("\nMenu:");
                        System.out.println("1. Enfileirar");
                        System.out.println("2. Desenfileirar");
                        System.out.println("3. Exibir");
                        System.out.print("Escolha uma opção: ");
                        int choice_queue = scanner.nextInt();
                        //after reading an integer it is necessary to put a reading to read the next line
                        scanner.nextLine();

                        switch (choice_queue){
                            //queue
                            case 1:
                                System.out.println("Informe o dado:");
                                String data_queue;
                                data_queue = scanner.nextLine();
                                queue.add_queue(data_queue);
                                break;
                                //dequeue
                             case 2:
                                 queue.dequeue();
                                break;
                                //display
                            case 3:
                                queue.print();
                                break;
                            default:
                                System.out.println("Opção inválida");
                        }

                        //ask if want to stay,if not,break the loop
                        System.out.println("Deseja sair deste módulo?[s/n]");
                        options_queue = scanner.nextLine();


                    }
                    System.out.println("====================================================");
                    break;
                default:
                    System.out.println("Opção inválida");
            }

            //ask if want to stay,if not,break the loop
            System.out.println("Deseja fechar o programa?[s/n]");
            String option_loop = scanner.nextLine();

            if(option_loop.equals("s")){
                break;
            }
            
        }
    }
}

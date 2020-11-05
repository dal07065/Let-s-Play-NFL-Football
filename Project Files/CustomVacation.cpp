#include "CustomVacation.h"
#include "ui_CustomVacation.h"



CustomVacation::CustomVacation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomVacation)
{

    ui->setupUi(this);
    this->setWindowTitle("Plan Your Trip");

    populateListWidget();


    connect(ui->pushButtonFirst,SIGNAL(clicked()),this, SLOT(pushButtonFirst_clicked()));
    connect(ui->pushButtonSecond,SIGNAL(clicked()),this, SLOT(pushButtonSecond_clicked()));
    connect(ui->pushButtonSouv1,SIGNAL(clicked()),this, SLOT(pushButtonSouv1_clicked()));
    connect(ui->pushButtonSouv2,SIGNAL(clicked()),this, SLOT(pushButtonSouv2_clicked()));
    connect(ui->listWidgetSecond, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(populateStartTeam(QListWidgetItem*)));

    int maximumChoice = Team::getTeams().size();
    ui->numberOfCitiesSpinBox->setMinimum(2);
    ui->numberOfCitiesSpinBox->setMaximum(maximumChoice);



}

void CustomVacation::setUserID(int i)
{
    userID = i;
}

CustomVacation::~CustomVacation()
{
    delete ui;
}

void CustomVacation::populateListWidget()
{
    int row=0;

     for (auto it = Team::teams.begin(); it != Team::teams.end(); ++it)
     {
           QListWidgetItem * item = new QListWidgetItem;
           QString text = QString::fromStdString(it->getTeamName());
           item->setData( Qt::UserRole, it->getTeamId());
           item->setText(text);

           ui->listWidgetFirst->addItem(item);

           row++;
     }



}

void CustomVacation::on_listWidgetFirst_itemDoubleClicked(QListWidgetItem *item)
{
    int data2 = item->data(Qt::UserRole).toInt();
    int data3 = item->data(Qt::UserRole+1).toInt();
     qDebug()<<item->text()<< data2<<"---"<< data3;
}

void CustomVacation::pushButtonFirst_clicked()
{
    if (ui->listWidgetFirst->count() == 0)
        return;
    if (ui->listWidgetFirst->currentItem() == nullptr)
        return;

    int TeamID = ui->listWidgetFirst->currentItem()->data(Qt::UserRole).toInt();
    vector<SouvenirType> souvenirV = Team::getSouvenirByTeamId(TeamID);
     for(auto it = souvenirV.begin(); it!= souvenirV.end();++it)
         {

             QListWidgetItem *newItem2 = new QListWidgetItem;
             newItem2->setData( Qt::UserRole, it->TeamID);
             newItem2->setData( Qt::UserRole+1, it->souvenirID);
             newItem2->setData( Qt::UserRole+2, it->price);
             newItem2->setText(QString::fromStdString( it->SouvenirName)+" ($"+QString::fromStdString(Team::formateNumbers(it->price))+")");
             ui->souvAvailable->insertItem(  ui->souvAvailable->count(),newItem2);
         }
     ui->souvAvailable->sortItems();
     souvenirV.clear();

     QListWidgetItem *newItem = new QListWidgetItem;
     newItem->setData( Qt::UserRole, ui->listWidgetFirst->currentItem()->data(Qt::UserRole).toInt());
     newItem->setText(ui->listWidgetFirst->currentItem()->text());
     newItem->setFlags( newItem->flags() | Qt::ItemIsUserCheckable); // set checkable flag
     newItem->setCheckState(Qt::Unchecked);
     ui->listWidgetSecond->insertItem( ui->listWidgetSecond->count()  ,newItem);
     ui->listWidgetSecond->sortItems();
     ui->listWidgetFirst->takeItem(ui->listWidgetFirst->currentRow());
     ui->listWidgetFirst->update();
updateCartDistance();
}



void CustomVacation::pushButtonSecond_clicked()
{
    if(ui->listWidgetSecond->currentItem()!=NULL)
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setData( Qt::UserRole, ui->listWidgetSecond->currentItem()->data(Qt::UserRole).toInt());
        newItem->setText(ui->listWidgetSecond->currentItem()->text());
        int TeamID = ui->listWidgetSecond->currentItem()->data(Qt::UserRole).toInt();
        ui->listWidgetFirst->insertItem( ui->listWidgetFirst->count() ,newItem);
        ui->listWidgetFirst->sortItems();

        int length = ui->souvAvailable->count()-1;
        for(int ii = length; ii >=0 ; --ii)
        {
            QListWidgetItem* item = ui->souvAvailable->item(ii);

            if(item->data(Qt::UserRole).toInt()==TeamID)
            {
                ui->souvAvailable->takeItem(ii);
            }
        }

        length = ui->souvSelected->count()-1;
        for(int ii = length; ii >=0 ; --ii)
        {
            QListWidgetItem* item = ui->souvSelected->item(ii);

            if(item->data(Qt::UserRole).toInt()==TeamID)
            {
                ui->souvSelected->takeItem(ii);
            }
        }
       ui->listWidgetSecond->takeItem(ui->listWidgetSecond->currentRow());
       ui->listWidgetFirst->update();
    }

updateCartDistance();
}


void CustomVacation::pushButtonSouv1_clicked()
{
    if (ui->souvAvailable->count() == 0)
        return;
    if (ui->souvAvailable->currentItem() == nullptr)
        return;

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setData( Qt::UserRole, ui->souvAvailable->currentItem()->data(Qt::UserRole).toInt());
    newItem->setData( Qt::UserRole+1, ui->souvAvailable->currentItem()->data(Qt::UserRole+1).toInt());
    newItem->setData( Qt::UserRole+2, ui->souvAvailable->currentItem()->data(Qt::UserRole+2).toFloat());
    newItem->setText(ui->souvAvailable->currentItem()->text());


    ui->souvSelected->insertItem( ui->souvSelected->count()  ,newItem);
    ui->souvSelected->sortItems();
    ui->souvAvailable->takeItem(ui->souvAvailable->currentRow());
    ui->souvAvailable->update();

updateCartDistance();
}
void CustomVacation::pushButtonSouv2_clicked()
{
    if(ui->souvSelected->currentItem())
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setData( Qt::UserRole, ui->souvSelected->currentItem()->data(Qt::UserRole).toInt());
        newItem->setData( Qt::UserRole+1, ui->souvSelected->currentItem()->data(Qt::UserRole+1).toInt());
        newItem->setData( Qt::UserRole+2, ui->souvSelected->currentItem()->data(Qt::UserRole+2).toFloat());
        newItem->setText(ui->souvSelected->currentItem()->text());
        ui->souvAvailable->insertItem( ui->souvAvailable->count()  ,newItem);
        ui->souvSelected->takeItem(ui->souvSelected->currentRow());
    }
   updateCartDistance();
}



void CustomVacation::populateStartTeam(QListWidgetItem* item)
{

    if( ui->listWidgetSecond->count()>=1)
    {
        int length = ui->listWidgetSecond->count()-1;
        for(int ii = 0; ii <=length ; ii++)
        {
            if(ui->listWidgetSecond->item(ii))
            {
               QListWidgetItem* itemX = ui->listWidgetSecond->item(ii);
               if(item != itemX && item->checkState()== Qt::Checked)
               {
                  itemX->setCheckState(Qt::Unchecked);
                }
            }
        }
    }
    updateCartDistance();

}

void CustomVacation::updateTotal()
{
    if(ui->souvSelected->count()>0)
    {
    float total=0;
    int length = ui->souvSelected->count()-1;
            for(int i = 0; i <=length ; i++)
            {
               QListWidgetItem* itemX = ui->souvSelected->item(i);
               int foodID = itemX->data( Qt::UserRole+1).toInt();
               float cost =  itemX->data( Qt::UserRole+2).toFloat();

               QList<QSpinBox*> spins = ui->scrollArea_2->findChildren<QSpinBox*>();
               for(int ii=0;ii<spins.count();ii++)
               {
                   if(spins[ii]->objectName()== "cart_quantity_"+itemX->data( Qt::UserRole+1).toString())
                   {
                       total+= spins[ii]->value()* cost;

                   }
               }
            }

            QList<QLabel*> labels = ui->scrollArea_2->findChildren<QLabel*>();;
            for(int ii=0;ii<labels.count();ii++)
            {
                if(labels[ii]->objectName()== "cartTotal")
                {
                   labels[ii]->setText("<b>$"+ QString::fromStdString( Team::formateNumbers(total))+"</b>");
                   break;
                }

            }
       }
}

bool CustomVacation::teamsSelected()
{
    bool flag= false;
    if( ui->listWidgetSecond->count()>=1)
    {
        int length = ui->listWidgetSecond->count()-1;
        for(int ii = 0; ii <=length ; ii++)
        {
            if(ui->listWidgetSecond->item(ii))
            {
               QListWidgetItem* itemX = ui->listWidgetSecond->item(ii);
               if( itemX->checkState()== Qt::Checked)
               {
                  flag = true;
                  break;
                }
            }
        }
    }
    return flag;
}

void CustomVacation::updateCartDistance()
{
    QLayoutItem *child;
    if( ui->scrollArea_2->layout())
    {
        while ((child = ui->scrollArea_2->layout()->takeAt(0)) != 0)
        {
            child->widget()->setParent(0);
            delete child;
        }
    }

    if( ui->scrollArea->layout())
    {
        while ((child = ui->scrollArea->layout()->takeAt(0)) != 0)
        {
            child->widget()->setParent(0);
            delete child;
        }
    }
    QWidget * container1 = new QWidget;
    QFormLayout *formLayout1 = new QFormLayout();

    container1->setLayout(formLayout1);
    ui->scrollArea->setWidget(container1);
    QHBoxLayout * hBoxLayout1= new QHBoxLayout;
    QLabel *txtLabel = new QLabel;


    if(teamsSelected())
    {
        selectedTeams.clear();
        int length = ui->listWidgetSecond->count()-1;
        int teamStart=0;
        for(int ii = 0; ii <=length ; ii++)
        {
           QListWidgetItem* itemX = ui->listWidgetSecond->item(ii);
           Team team= Team::getTeamById(itemX->data(Qt::UserRole).toInt());
           selectedTeams.push_back(team);
           if(itemX->checkState()== Qt::Checked){ teamStart = itemX->data(Qt::UserRole).toInt();}
        }
        QString str="<h3>Your vacation visit order:</h3><ol>";

        if(ui->listWidgetSecond->count() >1)
        {
             Team::orderTeamsByDistance(selectedTeams, teamStart);
             auto it = selectedTeams.begin();
             for (; it != selectedTeams.end(); ++it)
             {
                 str+="<li>"+QString::fromStdString(it->getTeamName())+"<li>";
             }
             float distance = Team::getTotalDistance(selectedTeams);
             ui->hiddenLabel->setVisible(false);
             ui->hiddenLabel->setText(QString::fromStdString(to_string(distance)));
             str+="</ol><h4>Total Kilometers: "+QString::number(distance)+" KM</h4>";
             txtLabel->setText(str);
        }
         hBoxLayout1->addWidget(txtLabel);
         formLayout1->addRow(hBoxLayout1);






         QWidget * container = new QWidget;
         QFormLayout *formLayout = new QFormLayout();
         container->setLayout(formLayout);
         ui->scrollArea_2->setWidget(container);
         QLabel *firstLabel = new QLabel;
         firstLabel->setText("<h3>Your food cart</h3>");
         formLayout->addRow(firstLabel);
         float total=0;
         if(ui->listWidgetSecond->count()>0)
         {

          length = ui->souvSelected->count()-1;
                  for(int ii = 0; ii <=length ; ii++)
                  {
                     QListWidgetItem* itemX = ui->souvSelected->item(ii);
                     QStringList list1 = itemX->text().split(QLatin1Char('('));
                     QLabel *FoodName = new QLabel;
                     FoodName->setText(list1[0]);
                     FoodName->setFixedSize(180,10);
                     QSpinBox *spin= new QSpinBox;
                     spin->setProperty("spin_id", itemX->data( Qt::UserRole+1).toInt());
                     spin->setRange(1,10);
                     spin->setObjectName("cart_quantity_"+itemX->data( Qt::UserRole+1).toString());

                     connect(spin, QOverload<int>::of(&QSpinBox::valueChanged),this,
                         [=](int i){

                         QList<QLabel*> labels = ui->scrollArea_2->findChildren<QLabel*>();
                          string x = "price_"+ to_string(sender()->property("spin_id").toInt());
                         for(int ii=0;ii<labels.count();ii++)
                         {
                             if(labels[ii]->objectName()== "cart_cost_"+sender()->property("spin_id").toString())
                             {
                                labels[ii]->setText("$"+QString::fromStdString(Team::formateNumbers((labels[ii]->property(x.c_str()).toFloat() * i))));
                                updateTotal();
                                break;
                             }

                         }



                     });

                     QLabel *FoodCost = new QLabel;
                     FoodCost->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
                     FoodCost->setText("$"+QString::fromStdString(Team::formateNumbers(itemX->data( Qt::UserRole+2).toFloat())));
                     string x =  "price_"+ to_string(itemX->data( Qt::UserRole+1).toInt());
                     FoodCost->setProperty(x.c_str(), itemX->data( Qt::UserRole+2).toFloat());
                     FoodCost->setObjectName("cart_cost_"+itemX->data( Qt::UserRole+1).toString());
                     QHBoxLayout * hBoxLayout= new QHBoxLayout;
                     hBoxLayout->addWidget(FoodName);
                     hBoxLayout->addWidget(spin);
                     hBoxLayout->addWidget(FoodCost);
                     formLayout->addRow(hBoxLayout);
                     formLayout->setSpacing(2);
                     total+=  itemX->data( Qt::UserRole+2).toFloat() * spin->value();

                  }

            }


                  QHBoxLayout * hBoxLayout= new QHBoxLayout;
                  QLabel *totalLabel = new QLabel;
                  totalLabel->setText("<b>Total</b>");
                  totalLabel->setFixedSize(180,20);

                  hBoxLayout->addWidget(totalLabel);
                  QLabel *FoodCost2 = new QLabel;
                  FoodCost2->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
                  FoodCost2->setText("<b>$"+QString::fromStdString(Team::formateNumbers(total))+"</b>");
                  FoodCost2->setObjectName("cartTotal");
                  hBoxLayout->addWidget(FoodCost2);
                  formLayout->addRow(hBoxLayout);



    }
    else
    {
        txtLabel->setText("<span style=\"color:red\">Select your starting Team!</span>");

        hBoxLayout1->addWidget(txtLabel);
        formLayout1->addRow(hBoxLayout1);
//        QMessageBox msgBox;
//        msgBox.setText("Error: You have to select destination Team and to check starting Team");
//        msgBox.exec();
    }

}




void CustomVacation::on_thirteenTeamPlan_clicked()
{

    //int row=0;
    ui->listWidgetFirst->clear();
    ui->listWidgetSecond->clear();
    ui->souvAvailable->clear();
    ui->souvSelected->clear();



     for (auto it = Team::teams.begin(); it != Team::teams.end(); ++it)
     {

           QString text = QString::fromStdString(it->getTeamName() );

           QListWidgetItem *newItem = new QListWidgetItem;
           newItem->setData( Qt::UserRole, it->getTeamId());
           newItem->setText(text);
           newItem->setFlags( newItem->flags() | Qt::ItemIsUserCheckable); // set checkable flag
           if (text != "Berlin")
               newItem->setCheckState(Qt::Unchecked);
           else
               newItem->setCheckState(Qt::Checked);

           int TeamID = it->getTeamId();
           vector<SouvenirType> souvenirV = Team::getSouvenirByTeamId(TeamID);
            for(auto it = souvenirV.begin(); it!= souvenirV.end();++it)
                {

                    QListWidgetItem *newItem2 = new QListWidgetItem;
                    newItem2->setData( Qt::UserRole, it->TeamID);
                    newItem2->setData( Qt::UserRole+1, it->souvenirID);
                    newItem2->setData( Qt::UserRole+2, it->price);
                    newItem2->setText(QString::fromStdString( it->SouvenirName)+" ($"+QString::fromStdString(Team::formateNumbers(it->price))+")");
                    ui->souvAvailable->insertItem(  ui->souvAvailable->count(),newItem2);
                }
            ui->souvAvailable->sortItems();

           ui->listWidgetSecond->addItem(newItem);

          // row++;
     }
     updateCartDistance();

}

void CustomVacation::on_bookYourTrip_clicked()
{
    if(teamsSelected())
    {
        //cartTotal
        float totatDistance= ui->hiddenLabel->text().toFloat() ;
        float totalFoodCost=0;

        std::vector<souvinerArr> mySelectedFood;
        if(ui->listWidgetSecond->count()>0)
        {
        float total=0;
        int length = ui->souvSelected->count()-1;
                for(int i = 0; i <=length ; i++)
                {
                   QListWidgetItem* itemX = ui->souvSelected->item(i);
                   int souvID = itemX->data( Qt::UserRole+1).toInt();
                   float cost =  itemX->data( Qt::UserRole+2).toFloat();

                   QList<QSpinBox*> spins = ui->scrollArea_2->findChildren<QSpinBox*>();
                   for(int ii=0;ii<spins.count();ii++)
                   {
                       if(spins[ii]->objectName()== "cart_quantity_"+itemX->data( Qt::UserRole+1).toString())
                       {
                           souvinerArr x ;
                           x.Price = cost;
                           x.Quantity = spins[ii]->value();
                           x.souvenirID = souvID;
                           mySelectedFood.push_back(x);
                           total+=  spins[ii]->value()* cost;
                       }
                   }
                }



                QSqlQuery query;
                 query.exec("insert into vacations  ( IdUser, TotalDistance, TotalCost) values ( 2, "+QString::fromStdString(to_string(totatDistance) )+" , "+QString::fromStdString(to_string(total))+" )");

                int last_id = query.lastInsertId().toInt();
                 qDebug()<<"last auto increment is"<<last_id ;

                 auto it = selectedTeams.begin();
                 for (; it != selectedTeams.end(); ++it)
                 {
                    query.exec("insert into vacations_teams (IdVacation, IdTeam) values ("+QString::fromStdString(to_string(last_id))+" , "+QString::fromStdString(to_string(it->getTeamId()))+" )");
                 }

                 auto it2 = mySelectedFood.begin();
                 for (; it2 != mySelectedFood.end(); ++it2)
                 {
                    query.exec("insert into vacations_souvenir (IdVacation, IdSouvenir, SouvenirPrice, Quantity) values ("+QString::fromStdString(to_string(last_id))+" , "+QString::fromStdString(to_string(it2->souvenirID))+" , "+QString::fromStdString(to_string(it2->Price))+" , "+QString::fromStdString(to_string(it2->Quantity))+" )");
                 }

                 //ui->result_lbl->setText("<span style=\"color:red\">Your Trip added successfully</span>");
                 ui->bookYourTrip->setVisible(false);
                 this->hide();
                 showVacationInfo();
                // showTripInfo();


           }


    }
    else
    {

      QWidget * container1 = new QWidget;
        QFormLayout *formLayout1 = new QFormLayout();

        container1->setLayout(formLayout1);
        ui->scrollArea->setWidget(container1);
        QHBoxLayout * hBoxLayout1= new QHBoxLayout;
        QLabel *txtLabel = new QLabel;
        txtLabel->setText("<span style=\"color:red\">Select your Teams and starting Team!</span>");
        hBoxLayout1->addWidget(txtLabel);
        formLayout1->addRow(hBoxLayout1);
    }
}

void CustomVacation::resetUI()
{

    ui->setupUi(this);

    populateListWidget();


    connect(ui->pushButtonFirst,SIGNAL(clicked()),this, SLOT(pushButtonFirst_clicked()));
    connect(ui->pushButtonSecond,SIGNAL(clicked()),this, SLOT(pushButtonSecond_clicked()));
    connect(ui->pushButtonSouv1,SIGNAL(clicked()),this, SLOT(pushButtonSouv1_clicked()));
    connect(ui->pushButtonSouv2,SIGNAL(clicked()),this, SLOT(pushButtonSouv2_clicked()));
    connect(ui->listWidgetSecond, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(populateStartTeam(QListWidgetItem*)));
    connect(ui->thirteenTeamPlan,SIGNAL(clicked()), this, SLOT(on_thirteenTeamPlan_clicked()));
    connect(ui->bookYourTrip, SIGNAL(clicked()), this, SLOT(on_bookYourTrip_clicked()));
    connect(ui->NumberTripPushButton, SIGNAL(clicked()), this, SLOT(on_NumberTripPushButton_clicked()));

    int maximumChoice = Team::getTeams().size();
    ui->numberOfCitiesSpinBox->setMinimum(2);
    ui->numberOfCitiesSpinBox->setMaximum(maximumChoice);

    show();
}

void CustomVacation::showVacationInfo()
{


   currentVacation = new VacationInfo();
   currentVacation->show();
   connect(currentVacation,SIGNAL(backToCustomVacation()),this,SLOT(resetUI()));
}

void CustomVacation::on_NumberTripPushButton_clicked()
{
    ui->listWidgetFirst->clear();
    ui->listWidgetSecond->clear();
    ui->souvAvailable->clear();
    ui->souvSelected->clear();


    int numberOfTeam = ui->numberOfCitiesSpinBox->value();
    int startingTeamID = -1;

    vector<Team> allCities = Team::getTeams();
    vector<Team> tripCities;


    for (auto it = Team::teams.begin(); it != Team::teams.end() ; ++it)
    {
           QString text = QString::fromStdString(it->getTeamName() );
           if (text == ("Paris"))
           {
               startingTeamID = it->getTeamId();
               break;
           }
    }



    Team::orderTeamsByDistance(allCities, startingTeamID);
    for (int i = 0; i < numberOfTeam; i++)
        tripCities.push_back(allCities[i]);

    for (auto it2 = tripCities.begin(); it2 != tripCities.end(); ++it2)
    {

          QString text = QString::fromStdString(it2->getTeamName() );

          QListWidgetItem *newItem = new QListWidgetItem;
          newItem->setData( Qt::UserRole, it2->getTeamId());
          newItem->setText(text);
          newItem->setFlags( newItem->flags() | Qt::ItemIsUserCheckable); // set checkable flag
          int teamID = it2->getTeamId();

          if (teamID != startingTeamID)
              newItem->setCheckState(Qt::Unchecked);
          else
              newItem->setCheckState(Qt::Checked);

          vector<SouvenirType> souvenirV = Team::getSouvenirByTeamId(teamID);
           for(auto it = souvenirV.begin(); it!= souvenirV.end();++it)
               {

                   QListWidgetItem *newItem2 = new QListWidgetItem;
                   newItem2->setData( Qt::UserRole, it->TeamID);
                   newItem2->setData( Qt::UserRole+1, it->souvenirID);
                   newItem2->setData( Qt::UserRole+2, it->price);
                   newItem2->setText(QString::fromStdString( it->SouvenirName)+" ($"+QString::fromStdString(Team::formateNumbers(it->price))+")");
                   ui->souvAvailable->insertItem(  ui->souvAvailable->count(),newItem2);
               }
           ui->souvAvailable->sortItems();

          ui->listWidgetSecond->addItem(newItem);

          //row++;
    }
    updateCartDistance();

    for (int i = numberOfTeam; i < allCities.size(); ++i)
    {
          QListWidgetItem * item = new QListWidgetItem;
          QString text = QString::fromStdString(allCities[i].getTeamName() );
          item->setData( Qt::UserRole, allCities[i].getTeamId());
          item->setText(text);

          ui->listWidgetFirst->addItem(item);
    }




}

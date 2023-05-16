<?php 
session_start();
include '../connexion_BD/connexion.php';
if(isset($_SESSION['id']))
{

    
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
    <style type="text/css">
            nav {
                display: flex;
                flex-wrap: wrap;
                justify-content:space-between;
                padding: 20px;
                background-color: #fff;
                position: sticky;
                top: 0;

            }
        nav h1 {
            font-size: 20px;
        }   
        nav .ong{
            display: flex;
            flex-wrap: wrap;
        }
        nav .ong p{
            font-size: 17px;
            margin-right: 15px;
            cursor: pointer;

        }

         a 
        {
            text-decoration: none;
            color: #000;

        }
       
       .menu {
        background-color:#D98880;
         height: 40vw;
        width: 19.7vw;
        position: fixed;
        
        
      
       }

       .menu tr td{
        width: 200px;
        text-align: center; 
        vertical-align: center;
        font-weight: bold;
         cursor: pointer;
       
        border: none;
       }
       .menu_g {
        display: flex;
        background-color: #f2f2f2;
       }
       .statistique {
       
        width: 80.2vw;
        margin-top: -20px;
        margin-left: 19.8vw;
                             
       }
       
       .statistique th,.statistique .head  {
        height: 100px;
        border: none;
        background-color: #EBE0E0;

       }
        
       .statistique tr td {
        width: 40.1vw;
        background-color: #f2f2f2;
        height: 60px;

       }
        .statistique tr td .items {
            height: 100px;
            
            background-color: #fff;
            padding: 15px;
            vertical-align: center;
            margin-top: 10px;
            margin-left: 10px;
            display: flex;
            justify-content: space-between;
            font-size: 20px;
            color: #524C4C;
        }
         .statistique tr td .items i {
            margin-top: 20px;
            margin-right: 30px;
            

         }
         .statistique tr td .items p{
            margin-left: 30px;

         }

         .statistique tr th p {
            text-align: left;
            margin-left: 30px;
            font-size: 30px;
            margin-bottom: 15px;
            font-weight: ;
         }
         .statistique ,tr,td {
             border: 1px solid #f2f2f2;
            border-collapse: collapse;

         }
         .statistique tr td{
            text-align: center;
            vertical-align: center;
            background-color: #fff;
         }
        
         .statistique #titre td{
           font-size: 15px;
          font-weight: bold;
          background-color: #f2f2f2;
         }
         .statistique:nth-child(even)
         { background-color: #fff; }
         i {
            margin-right: 10px;
         }
         .statistique .head button {
            border: none;
            outline: none;
            width: 150px;
            height: 50px;
            font-size: 15px;
            cursor: pointer;
            background-color: #D98880;
            border-radius: 50px;
            font-weight: bold;
            margin-top: 15px;

         }

    </style>
</head>
<body style="margin: 0px; padding: 0px; font-family: sans-serif,Open Sans;">
    <nav>
        <h1>Boutique.net</h1>
        <div class="ong">
                <a href="profil.php"><p class="link" ><i class="fas fa-user"> Profil </i></p></a>
                <p class="link">
                    <a href="../connexion_BD/logout.php" style="color: black;">
                        <i class="fas fa-sign-out-alt"> Se déconnecter</i>
                    </a>
                </p>
        </div>    
    </nav>
  
     <div class="menu_g">
            <table class="menu">
                <tr>
                    <td><a href="./"><div class="menu_items">TABLEAU DE BORD</div></a></td>
                </tr>
                <tr>
                    <td><a href="Clients.php"><div class="menu_items">CLIENTS</div></a></td>
                </tr>
                <tr>
                    <td><a href="Articles.php"><div class="menu_items">ARTICLES</div></a></td>
                </tr>
                <tr>
                    <td><a href="Commandes.php"> <div class="menu_items">COMMANDES</div></a></td>
                </tr>
                    <td><a href="Commentaires.php"> <div class="menu_items">COMMANTAIRES</div></a></td>
                </tr>
            </table>           
            <table class="statistique">
                    <tr>
    
                        <th colspan="7">
                            <p>Gérer les articles</p> 
                        </th>
                        <td class="head" colspan="2"><button><a href="AjouterArticle.php">Ajouter Article </a></button></td>
                        
                       
                    </tr>
                    <tr id="titre">    
                    
                        <?php 

                        $req="exec ps_Articles";
                        $params = array();
                        $options =  array( "Scrollable" => SQLSRV_CURSOR_KEYSET );
                        $res = sqlsrv_query($conn,$req,$params ,$options);
                        $row_count = sqlsrv_num_rows( $res);
                        if($row_count<=0)
                            {
                                
                               echo '<td colspan="9">Rien na été trouvé dans la base de données.</td>' ;
                                
                            }
                        else
                            {
                            
                                echo 
                                '<td ">Id</td>
                                <td ">Designation </td>
                                <td ">Discreption</td>
                                <td ">Type</td>
                                <td ">Taille</td>
                                <td ">Couleur</td>
                                <td ">Prix</td>
                                <td ">Qautité Stock</td>
                                 <td ">Action</td>

                        </tr>        ';

                        while($row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC))
                            {
                                echo '
                                    <tr>
                                         <td >'.trim($row['IdArticle']).' </td> 
                                        <td >'.trim($row['DesignationArticle']).' </td>
                                        <td >'.trim($row['DescriptionArticle']).'</td>
                                        ';
                                        if($row['IdType']==1)
                                        {
                                            echo '<td>FEMMES</td>';
                                        }
                                        else if($row['IdType']==2)
                                        {
                                            echo '<td>HOMMES</td>';
                                        }
                                        else{
                                            echo '<td>ENFANTS</td>';
                                        }
                                        echo'
                                        <td >'.trim($row['TailleArticle']).'</td>
                                        <td >'.trim($row['CouleurArticle']).'</td>
                                        <td >'.number_format($row['PrixArticle'],2,',',' ').'dhs</td>
                                        <td >'.$row['QtStock'].'</td>
                                        <td ><a href="Supprimer.php?idArticle='.$row['IdArticle'].'"><i class="fas fa-trash-alt"></i></a> 
                                            <a href="modifierArticle.php?idArticle='.$row['IdArticle'].'"><i class="fas fa-sync"></i></a>
                                        </td>
                                    </tr>
                                ';
                            }
                                                

                            }
                        ?>
                   
                                          
             </table>
               
    </div>
          
</body>
</html>
<?php
}
else {
    header("Location : ../index.php");
}

?>
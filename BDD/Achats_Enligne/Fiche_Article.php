<?php 
session_start();
include "connexion_BD/connexion.php";
include "panier.class.php";
$panier=new panier();
if($_GET['IdArticle'] && isset($_SESSION['id']))
{
	
?>
<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<title>Fiche Article </title>
	<style type="text/css">
		body{
			margin-top:20px ;
			margin-bottom:20px ;
		}
		table{
			margin:15px auto;
			width: 85vw;
			
		}
		table tr th, table tr td {
			height: 50px;
		}

		 table,th,td, tr {
        
        border: 2px solid #f2f2f2;
        border-collapse: collapse;
      }
      tr th,tr td {
      	padding: 10px;
      }
      table tr td img {
      	margin: 5px;
      	width: 300px;
      	height: 150px;
      }
      table tr td.CH {
      font-weight: bold;
      }
      form {
      	margin-top: 20px;
      	vertical-align: left;
      	
      }
      .buttons {
      	margin-right: 50px;
      	display: flex;
      	justify-content: right;
      }
      button ,.btn {
      	width: 230PX;
      	padding: 15px 25px;
      	margin-left: 50px;
      	text-align: center;
      	border-radius: 5px;
      	outline: none;
      	border: none;
      	color: #fff;
      	padding: 15px 25px;
      	cursor: pointer;
      	background-color: #D98880 ;
      	font-size: 15px;
      	font-weight: bold;
      	margin: 15px auto;
      	 }
      	 input  {
      	 	margin: 15px auto;
      	 	width: 84.5vw;
      	 	height: 5vw;
      	 	border: 1px solid gray;
      	 	outline: none;
      	 } 
      	 label {
      	 	margin-top: 15px;
      	 	font-size: 20px;
      	 	font-weight: bold;
      	 	color: gray;
      	 	margin: 15px auto;
      	 	width: 85vw;

      	 }
      	 div
      	 {	
      	 	margin: 15px auto;
      	 	width: 85vw;
      	 }
      	 div .utl {
      	 	border: none;
      	 	font-weight: bold;
      	 	margin-bottom: -20px;

      	 }
      	 div p {
      	 	padding: 10px;
      	 	border: 1px dotted #f2f2f2;
      	 	
      	 }
      	 .cmnt {
      	 	margin-top: 40px;
      	 	margin: 15px auto;
      	 	width: 85vw;
      	 	font-weight: bold;
      	 }
      	 #image td {
      	 	height: 300px;

      	 }
      	 table tr th {
      	 	background-color: #f2f2f2;
      	 }
      	 table tr td {
      	 	padding-left: 30px;
      	 }
      
      	a{
      		text-decoration: none;
      		color: #fff;
      		font-size: 15px;
      	 	font-weight: bold;
      	 	margin-top:30px ;

      	}

      	 
	</style>
</head>
<body style="margin: 0px; padding: 0px; font-family: sans-serif,Open Sans;">

	<?php
	$art=$_GET['IdArticle'];
	$sql="exec ps_donnees_Article '$art'";
	$res=sqlsrv_query($conn,$sql);
	$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
	?>
	<table>
		<tr>
			<th>
				Champ
			</th>
			<th>
				Valeur
			</th>
		</tr>
		<tr>
			<td class="CH">
				Designation d'article
			</td>
			<td>
				<?php 
				echo $row['DesignationArticle'];
				?>		
			</td>
		</tr>
		<tr>
			<td class="CH">
				Prix Unitaire de l'article
			</td>
			<td>
				<?php 
				echo number_format($row['PrixArticle'],2);
				?>		
			</td>
		</tr>
		<tr>
			<td class="CH">
				Taille  de l'article
			</td>
			<td>
				<?php 
				echo $row['TailleArticle'];
				?>		
			</td>
		</tr>
		<tr>
			<td class="CH">
				Couleur de l'article
			</td>
			<td>
				<?php 
				echo $row['CouleurArticle'];
				?>		
			</td>
		</tr>
		<tr>
			<td class="CH">
				Description de l'article
			</td>
			<td>
				<?php 
				echo $row['DescriptionArticle'];
				?>		
			</td>
		</tr>
		<tr id='image'>
			<td class="CH">
				Images de l'article
			</td>
			<td >
				<?php
				echo '<img src="'.$row['CheminImage'].'">';
				while (	$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC)) {
				echo '<img  src="'.$row['CheminImage'].'">';
				}

		
				?>		
			</td>
		</tr>	
	</table>
		<?php 

		$art=$_GET['IdArticle'];
		$sql="exec ps_utilisateur_commenter_sur_Article '$art'";
		//$res=sqlsrv_query($conn,$sql);
		$params = array();
		$options =  array( "Scrollable" => SQLSRV_CURSOR_KEYSET );
			//$res = sqlsrv_query($conn,$sql);
		$res = sqlsrv_query($conn,$sql,$params ,$options);
		$nbr_row=sqlsrv_num_rows( $res);
		if($nbr_row>0)
			{	echo "<p class='cmnt'>Les commentaires sur l'article: </p>"; 
				while($row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC))
				{	
					echo '
					<div class="comnt">';
	?>
	<?php
		if($_SESSION['id']==trim($row['IdUtilisateur']))
			
		{
			echo '<p class="utl">Vous</p>';

		}
		else
		{
			echo '<p class="utl">'.$row['PrenomUtilisateur'].' '.$row['NomUtilisateur'].'</p>';
		}
			
						
		echo '<p>'.$row['TextComment'].'</p>
		</div>';

					
				}

			}
	?>
	
		
	<div >
		<form method="POST" action="inserer_Comment.php?idArticle=<?= $_GET['IdArticle']; ?>">
			<label>Insérer un autre commentaire sur l'article</label>
			<input type="text" name="comt" placeholder="Insérer un commentaire sur l'article">
			<input type="submit" name="submit"  class="btn" value="Ajouter Commentaire">
		</form>
		<button class="btn"><a href="ajouterpanier.php?id=<?=$_GET['IdArticle'];?>">Ajouter au panier</a></button>
	</div>	
	
</html>
<?php 
}
else
{
	header("Location : home.php");
}
?>
 <?php
session_start();
include "connexion_BD/connexion.php";
include 'header.php';
if(isset($_SESSION['prenom']) && isset($_SESSION['id']) )
{

?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Home</title>
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<style type="text/css">
		header {
			display: flex;
			justify-content: center;
			align-items: center;
			flex-direction: column;
		}
		header h1{
			font-size: 50px;
			max-width: 500px;
			text-align: center;
		}
		header button {
			font-size: 20px;
			padding: 15px 20px;
			border: none;
			border-radius: 5px;
			outline: none;
			cursor: pointer;

		}
		.main {
			margin: 20px;
			margin-top: 80px;
			display: flex;
			flex-direction: column;
			justify-content: center;
			align-items: center;
		}
		.cards{
			display: flex;
			flex-wrap: wrap;

		}
		.cards .card {
			margin-right: 20px;
			cursor: pointer;
		}
		.cards .card img {
			width: 300px;
			height: 300px;
		}
		.cards .card .card-header
		{
			display: flex;
			justify-content: space-between;
			flex-wrap: wrap;
		}

		.cards .card .card-body p{
			margin-top: -10px;
		}
		

	</style>
		
</head>
<body >
		<header>
			<h1>
				Bienvenue <span style="color: #eb7371;"><?php echo $_SESSION['prenom'] ?></span> dans votre boutique, votre chez vous.
			</h1>
			<button>
				Naviguer <i class="fas fa-paper-plane"></i>
			</button>
		</header>
		<section class="main">
			<div class="cards">
			
					<?php 
					$sql= "exec ps_Article_par_Type 'HOMMES'";
					$res=sqlsrv_query($conn,$sql);
					while($row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC))
						{	echo '
							<div class="card">
							<a href="Fiche_Article.php?IdArticle='.$row['IdArticle'].'"><img src='.$row['CheminImage'].'></a><br>
								<div class="card-header">
									<h4 class="title">'.$row['DesignationArticle'].'</h4>
									<h4 class="prix">'.number_format($row['PrixArticle'],2).' dh</h4>
								</div>
								<div class="card-body">
									<p>'.$row['DescriptionArticle'].'</p>
								</div>
							</div>'	;

						}


					?>
					</div>

		</section>
		<?php
		include 'footer.php';
		?>





</body>
</html>
<?php 
}
else { 
	header("Location: connecter.php");
	exit();
}
?>